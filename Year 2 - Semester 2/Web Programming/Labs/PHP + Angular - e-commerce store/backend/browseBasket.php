<?php
    // Enable CORS
    header("Access-Control-Allow-Origin: *");
    header("Access-Control-Allow-Methods: GET, POST, OPTIONS");
    header("Access-Control-Allow-Headers: Content-Type");
    // database connection
    $conn = new mysqli("localhost", "root", "", "e-commerce");

    if (!$conn) {
        die('Could not connect: ' . mysqli_error($con));
    }

    // get the products from the cart
    $sql = "SELECT c.ID, p.NAME, p.CATEGORY, p.PRICE
            FROM CART c
            INNER JOIN PRODUCTS p ON c.PRODUCT_ID = p.ID";
    $result = $conn->query($sql);
    $products = $result->fetch_all(MYSQLI_ASSOC);

    // close database connection
    $conn->close();

    // Set the response headers
    header("Content-Type: application/json");

    // Convert the products array to JSON
    $jsonResponse = json_encode($products);

    // Return the JSON response
    echo $jsonResponse;
?>
