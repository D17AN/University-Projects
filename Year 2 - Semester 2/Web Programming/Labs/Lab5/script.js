const X_CLASS = 'x';
const CIRCLE_CLASS = 'circle';
const cellElements = document.querySelectorAll('[data-cell]');
const board = document.getElementById('board');
const WINNING_COMBINATIONS = [  
    [0, 1, 2], [3, 4, 5], [6, 7, 8],
    [0, 3, 6], [1, 4, 7], [2, 5, 8],
    [0, 4, 8], [2, 4, 6]
]

const winningMessageElement = document.getElementById("winningMessage");
const winningMessageTextElement = document.querySelector('[data-winning-message-text]'); 
const restartButton = document.getElementById('restartButton');
let circleTurn;

startGame();

restartButton.addEventListener('click', startGame);

function startGame(){
    circleTurn = false;
    cellElements.forEach(cell => {
        cell.classList.remove(X_CLASS);
        cell.classList.remove(CIRCLE_CLASS);
        cell.removeEventListener('click', handleClick);
        cell.addEventListener('click', handleClick, {once: true});
    });
    setBoardHoverClass();
    winningMessageElement.classList.remove('show');
}


function handleClick(e){
    //place mark
    //check for draw
    //check for win
    //switch turns
    const cell = e.target;
    console.log(e.target.id);
    const currentClass = circleTurn ? CIRCLE_CLASS : X_CLASS;
    placeMark(cell, currentClass);
    if (checkWin(currentClass)){
        endGame(false);
    }else if (isDraw()){
        endGame(true);
    }else{
        swapTurns();
        setBoardHoverClass();
        // If it's the computer player's turn, generate a move and mark the board
        if (circleTurn){
            const computerMove = generateMove();
            const computerCell = cellElements[computerMove];
            placeMark(computerCell, CIRCLE_CLASS);
            if (checkWin(CIRCLE_CLASS)){
                endGame(false);
            }else if (isDraw()){
                endGame(true);
            }else{
                swapTurns();
                setBoardHoverClass();
            }
        }
    }
}


function isDraw(){
    return [...cellElements].every(cell => { 
        return cell.classList.contains(X_CLASS) || cell.classList.contains(CIRCLE_CLASS);
    });
}


function checkWin(currentClass){
    return WINNING_COMBINATIONS.some(combination => {
        return combination.every(index => {
            return cellElements[index].classList.contains(currentClass);
        })
    });
}


function endGame(draw){
    if(draw){
        winningMessageTextElement.innerText = 'Draw!';
    }else{
        winningMessageTextElement.innerText = `${circleTurn ? "You lost!" : "You won!"}`;
    }
    winningMessageElement.classList.add('show');

}


function placeMark(cell, currentClass){
    cell.classList.add(currentClass);  
}


function swapTurns(){
    circleTurn = !circleTurn;
}


function generateMove(){
    const min = 0;
    const max = 8;
    let randomInteger = Math.floor(Math.random() * (max - min + 1)) + min;
    while(cellElements[randomInteger].classList.contains(X_CLASS) || cellElements[randomInteger].classList.contains(CIRCLE_CLASS)){
        randomInteger = Math.floor(Math.random() * (max - min + 1)) + min;
    }
    return randomInteger;
}


function setBoardHoverClass(){
    board.classList.remove(X_CLASS);
    board.classList.remove(CIRCLE_CLASS);
    if(circleTurn){
        board.classList.add(CIRCLE_CLASS);
    }
    else{
        board.classList.add(X_CLASS);
    }
}