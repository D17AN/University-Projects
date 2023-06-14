
--a)Union
--1)Find the IDs of customers called Popescu and of those who ordered pre_workout
SELECT C.CID
FROM CUSTOMER C
WHERE C.LAST_NAME = 'POPESCU'
UNION
SELECT O.CID
FROM ORDER_ O
WHERE O.DESCRIPTION = 'PRE_WORKOUT'
/*2)*/
SELECT DISTINCT C.LAST_NAME, C.FIRST_NAME
FROM CUSTOMER C, ORDER_ O
WHERE (O.CID = C.CID AND O.PRICE > 210) OR (C.CID = 1 AND O.PRICE < 210)

--b) 2 queries with the intersection operation; INTERSECT AND IN

--1) All the products of type whey and are < 200*/

SELECT P.NAME 
FROM PRODUCT P
WHERE P.TYPE LIKE '%WHEY%'
INTERSECT
SELECT P1.NAME
FROM PRODUCT P1
WHERE P1.PRICE < 200

--2)the same, only with IN

SELECT P.NAME
FROM PRODUCT P
WHERE P.TYPE LIKE '%WHEY%' AND P.NAME IN (SELECT P1.NAME FROM PRODUCT P1 WHERE P1.PRICE < 200) 


--c) two queries with the difference operation; use EXCEPT and NOT IN

--1)ID Products which are > 160, but aren't in any inventory*/

SELECT P.PID 
FROM PRODUCT P
WHERE P.PRICE > 160
EXCEPT
SELECT I.PID
FROM INVENTORY I

--2)same question, but using NOT IN

SELECT P.PID
FROM PRODUCT P
WHERE(P.PRICE > 160) AND P.PID NOT IN(SELECT I.PID FROM INVENTORY I)

/*
d)4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN(one query per operator);
one query will join at least 3 tables, while another one will join at least two m:n relationships
*/
--1)INNER JOIN | GET FOR ORDER THE NAME OF THE CUSTOMER*/

SELECT C.LAST_NAME, C.FIRST_NAME, O.CID, O.DESCRIPTION, O.PRICE 
FROM ORDER_ O INNER JOIN CUSTOMER C ON C.CID = O.CID


/*2)LEFT JOIN | PRINT ALL THE FACTORIES AND THEIR UTILITY MACHINES AND THEIR WAREHOUSES*/

SELECT F.FID, F.TYPE, UM.TYPE, W.NAME
FROM FACTORY F
LEFT JOIN UTILITY_MACHINE UM ON F.FID = UM.FID
LEFT JOIN WAREHOUSE W ON F.FID = W.FID


/*3)RIGHT JOIN | print all the employees including the department they work; include the employees that doesn't work in any depart.*/

SELECT E.LAST_NAME, E.FIRST_NAME, D.NAME
FROM EMPLOYEE E
RIGHT JOIN WORK_AT WT ON WT.EID = E.EID
RIGHT JOIN DEPARTMENT D ON D.DID = WT.DID

SELECT E.LAST_NAME, E.FIRST_NAME, D.NAME, F.TYPE, W.NAME, I.QUANTITY, P.NAME
FROM EMPLOYEE E
INNER JOIN WORK_AT WT ON WT.EID=E.EID
INNER JOIN DEPARTMENT D ON D.DID = WT.DID
INNER JOIN FACTORY F ON F.DID = D.DID
INNER JOIN WAREHOUSE W ON W.FID = F.FID
INNER JOIN INVENTORY I ON I.WID = W.WID
INNER JOIN PRODUCT P ON P.PID = I.PID

/*
e)2 queries with the IN operator and a subquery in the WHERE clause; 
in at least one case, the subquery must include a subquery in its own WHERE clause;
*/

--1) Products which are not in any of the warehouses.


SELECT P.*
FROM PRODUCT P
WHERE P.PID NOT IN(
					SELECT P3.PID
					FROM PRODUCT P3
					INNER JOIN INVENTORY I ON I.PID = P3.PID
					INNER JOIN WAREHOUSE W ON I.WID = W.WID
				  )

/*2)Name of departments which have employees which has their last name ended in 'RU' */
SELECT D.NAME
FROM DEPARTMENT D
WHERE D.DID IN(
				SELECT WT.DID
				FROM WORK_AT WT
				WHERE WT.EID IN(
								SELECT E.EID 
								FROM EMPLOYEE E
								WHERE E.LAST_NAME LIKE '%RU'
							   )
			  )

--f) 2 queries with the EXITS operator and a subquery in the WHERE clause.

/*1)Show the employees which are currently working in at least 1 department*/

SELECT E.LAST_NAME, E.FIRST_NAME, E.SALARY + 2700 AS NEW_SALARY
FROM EMPLOYEE E
WHERE EXISTS(
			 SELECT *
			 FROM EMPLOYEE E2
			 INNER JOIN WORK_AT WT ON WT.EID = E2.EID
			 INNER JOIN DEPARTMENT D ON D.DID = WT.DID
			 WHERE E2.EID = E.EID
			)

/*2)Show the non-empty warehouses*/

SELECT W.*
FROM WAREHOUSE W
WHERE EXISTS(
			 SELECT *
			 FROM PRODUCT P
			 INNER JOIN INVENTORY I ON I.PID = P.PID
			 INNER JOIN WAREHOUSE W2 ON W2.WID = I.WID
			 WHERE W.WID = W2.WID
			)

--g) 2 queries with a subquery in the FROM clause

/*
1)
Find all the employees whose salary is greater than the average budget
of all the departments
*/
SELECT E.EID, E.LAST_NAME, E.FIRST_NAME, E.SALARY
FROM 
( 
SELECT AVG(BUDGET) AS AverageBudget
FROM DEPARTMENT
) AS BUDGET, EMPLOYEE E
WHERE EXISTS
(
SELECT WA.EID
FROM WORK_AT AS WA
WHERE WA.EID = E.EID
) AND E.SALARY > BUDGET.AverageBudget


/*
2)
Find all the employees which have a salary <= 50000 and work
in at least 2 departments. They're going to get a bonus of 160.
*/

SELECT e.LAST_NAME, e.FIRST_NAME, E.SALARY + 200 AS new_paycheck
FROM
(
SELECT *
FROM EMPLOYEE E
WHERE E.SALARY <= 50000
)e
WHERE e.EID IN
(
SELECT WT.EID
FROM WORK_AT WT
GROUP BY WT.EID
HAVING COUNT(*) > 1
)
ORDER BY new_paycheck ASC



/*
h) 4 queries with GROUP BY clause, 3 of which also contain having clause;
2 of the latter will also have a subquery in the having clause;
use the aggregation operators; count, sum, avg, min, max;
*/

--1) Print locations and the number of factories which the company has there. 

SELECT F.LOCATION, COUNT(*) AS FACTORIES
FROM FACTORY F
GROUP BY F.LOCATION


--2) Print the departments with the most employees.
SELECT D.DID, D.NAME, COUNT(*) AS EMPLOYEES
FROM DEPARTMENT D INNER JOIN WORK_AT WT ON D.DID = WT.DID INNER JOIN EMPLOYEE E ON E.EID = WT.EID
GROUP BY D.DID, D.NAME
HAVING COUNT(*) = (
		/*get the max nr of employees for a department*/
		SELECT MAX(P.C)
		FROM(
				SELECT COUNT(*) C
				FROM DEPARTMENT D2 INNER JOIN WORK_AT WT2 ON D2.DID = WT2.DID INNER JOIN EMPLOYEE E2 ON E2.EID = WT2.EID
				GROUP BY D2.DID, D2.NAME
		)P
)

/*Display the nr of employees for each department*/
SELECT D.DID, D.NAME, COUNT(*) AS EMPLOYEES
FROM DEPARTMENT D INNER JOIN WORK_AT WT ON D.DID = WT.DID
GROUP BY D.DID, D.NAME


/*
3) Get the minimum price of the sum of prices of products of a certain type
*/

SELECT P.TYPE, SUM(P.PRICE) AS TOTAL_PRICE
FROM PRODUCT P
GROUP BY P.TYPE
HAVING SUM(P.PRICE) = (
		SELECT MIN(R.price)
		FROM 
		(
		SELECT SUM(P2.PRICE) price
		FROM PRODUCT P2
		GROUP BY P2.TYPE
		)R
)


/*
4)  Get the average price for products of a certain type with at least 1 product
which worth more than 200
*/

SELECT P.TYPE, AVG(P.PRICE) AS AVERAGE_PRICE
FROM PRODUCT P
GROUP BY P.TYPE
HAVING 0 < (
			SELECT COUNT(P2.TYPE)
			FROM PRODUCT P2
			WHERE P.TYPE = P2.TYPE AND P2.PRICE > 200
			)



/*
i) 4 queries using ANY and ALL to introduce a subquery in the WHERE clause 
	(2 queries per operator); rewrite 2 of them with aggregation operators, 
	and the other 2 with IN / [NOT] IN.
*/

/*
1) Top 2 products which are more expensive than the least expensive product of 
type WHEY ISOLATE.
*/
SELECT TOP 2 P.*
FROM PRODUCT P
WHERE P.PRICE > ANY(
					SELECT P2.PRICE
 					FROM PRODUCT P2
					WHERE P2.TYPE = 'WHEY ISOLATE'
				   )
ORDER BY P.PRICE DESC

/*rewritten with aggregation operator*/
SELECT TOP 2 P.*
FROM PRODUCT P
WHERE P.PRICE > (
				 SELECT MIN(P2.PRICE)
				 FROM PRODUCT P2
				 WHERE P2.TYPE = 'WHEY ISOLATE')
ORDER BY P.PRICE DESC


/*2) Find all the employees which were hired after 2018 in a department.*/

SELECT E.*
FROM EMPLOYEE E
WHERE E.EID = ANY(
				  SELECT WT.EID
				  FROM WORK_AT WT
				  WHERE WT.EMPLOYNMENT_DATE >= '2019-01-01'
				  )

/*Rewritten with IN*/
SELECT E.*
FROM EMPLOYEE E
WHERE E.EID IN(
			   SELECT WT.EID
			   FROM WORK_AT WT
			   WHERE WT.EMPLOYNMENT_DATE >= '2019-01-01'
			  )
/*
3) The top 30% income earners of the employees which salary is bigger after a paycheck cut of
	25000 than the employees with a salary smaller of 50000
*/

SELECT TOP 30 PERCENT E.*
FROM EMPLOYEE E
WHERE E.SALARY - 25000 > ALL(
							 SELECT E2.SALARY
							 FROM EMPLOYEE E2
							 WHERE E2.SALARY <= 50000
							)
ORDER BY E.SALARY DESC

/*MAX instead of ALL*/
SELECT TOP 30 PERCENT E.*
FROM EMPLOYEE E
WHERE E.SALARY - 25000 >   (
							SELECT MAX(E2.SALARY)
							FROM EMPLOYEE E2
							WHERE E2.SALARY <= 50000
						   )
ORDER BY E.SALARY DESC

/*
4) All the departments which don't have a factory which location is not in CLUJ-NAPOCA
*/

SELECT D.*
FROM DEPARTMENT D
WHERE D.DID <> ALL(
				   SELECT F.DID
				   FROM FACTORY F
				   WHERE F.LOCATION LIKE '%SUCEAVA%'
				  )

/*rewritten using NOT IN*/

SELECT D.*
FROM DEPARTMENT D
WHERE D.DID NOT IN(
					SELECT F.DID
					FROM FACTORY F
					WHERE F.LOCATION LIKE '%SUCEAVA%'
				   )