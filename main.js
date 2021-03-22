window.onload = function() {
    init();
};

var numCards = 6;
var gameOver = false;
var colors = [];
var pickedColor;
var mode = 1;;
var body = document.querySelector("body");
var cards = document.querySelectorAll(".card");
var colorDisplay = document.getElementById("color-picked");
var messageDisplay = document.querySelector("#message");
var h1 = document.querySelector("h1");
var resetButton = document.querySelector("#reset");
var resetDisplay = document.querySelector("#reset span");
var easybtn = document.querySelector('#easybtn');
var hardbtn = document.querySelector('#hardbtn');
var nightmarebtn = document.querySelector('#nightmarebtn');
var seconds = document.getElementById("seconds");
var countdown; 
var flash;



function init() {
    initCards();
    reset();
    
}
easybtn.addEventListener("click",function(){
    mode = 0;
    easybtn.classList.add("selected");
    hardbtn.classList.remove("selected");
    nightmarebtn.classList.remove("selected");
    numCards = 3;
    reset();
})
hardbtn.addEventListener('click',function(){
    mode = 1;
    easybtn.classList.remove("selected");
    hardbtn.classList.add("selected");
    nightmarebtn.classList.remove("selected");
    numCards = 6;
    reset();
});
nightmarebtn.addEventListener('click',function(){
    mode = 2;
    easybtn.classList.remove("selected");
    hardbtn.classList.remove("selected");
    nightmarebtn.classList.add("selected");
    numCards = 6;
    reset();
});


function initCards() {
    for (var i = 0; i < cards.length; i++) {
        //add click listeners to cards
        cards[i].addEventListener("click", function() {
            if (gameOver)
                return;
            //grab color of clicked card
            var clickedColor = this.style.backgroundColor;
            // alert(this.style.backgroundColor);
            //compare color to pickedColor
            if (clickedColor === pickedColor) {
                seconds.textContent = '';
                clearInterval(flash);
                clearInterval(countdown);
                messageDisplay.textContent = "Correct!";
                resetDisplay.textContent = "Play Again"
                changeColors("#FFF");
                body.style.backgroundColor = clickedColor;
                resetButton.style.display = 'block';
                gameOver = true;
            } else {
                this.style.opacity = 0;
                messageDisplay.textContent = "Try Again";
            }
        });
    }
    
}
var time;
function reset() {
    gameOver = false;
    colors = generateRandomColors(numCards);
    //pick a new random color from array
    pickedColor = pickColor();
    //change colorDisplay to match picked Color
    colorDisplay.textContent = pickedColor;
    resetDisplay.textContent = "New Color"
    messageDisplay.textContent = "What's the Color?";
    //change colors of cards
    for (var i = 0; i < cards.length; i++) {
        cards[i].style.opacity = 1;
        if (colors[i]) {
            cards[i].style.display = "block"
            cards[i].style.backgroundColor = colors[i];
        } else {
            cards[i].style.display = "none";
        }
    }
    body.style.backgroundColor = "#232323";
    if(mode == 2){
        time = 4;
        seconds.style.display = 'inline';
        seconds.textContent = ' 5';
        resetButton.style.display = 'none';
        countdown = setInterval(function(){
            seconds.style.display = 'inline';
            seconds.textContent = ' ' + time;
            body.style.backgroundColor = "#838383";
            flash = setTimeout(function() {
                body.style.backgroundColor = "#232323";
            }, 200);
            if(time === 0){
                seconds.style.display = 'none';
                messageDisplay.textContent ="TIMEOUT!!!";
                changeColors("#FFF");
                gameOver = true;
                body.style.backgroundColor = pickedColor;
                resetButton.style.display = 'block';
                clearInterval(countdown);
                clearInterval(flash);
                }
            time--;
        },1000);
    }
       
    else{
        clearInterval(flash);
        clearInterval(countdown);
        time = '';
        seconds.textContent = null;
        messageDisplay.textContent = "What's the Color?";
        //if(countdown!=null)clearInterval(countdown);
        resetButton.style.display = 'block';
        seconds.style.display = "none";
    }
    
}

resetButton.addEventListener("click", function() {
    reset();
})

function changeColors(color) {
    //loop through all cards
    for (var i = 0; i < cards.length; i++) {
        //change each color to match given color
        cards[i].style.opacity = 1;
        cards[i].style.backgroundColor = color;
    }
}

function pickColor() {
    var random = Math.floor(Math.random() * colors.length);
    return colors[random];
}

function generateRandomColors(num) {
    //make an array
    var arr = []
    //repeat num times
    for (var i = 0; i < num; i++) {
        //get random color and push into arr
        arr.push(randomColor())
    }
    //return that array
    return arr;
}

function randomColor() {
    //pick a "red" from 0 - 255
    var r = Math.floor(Math.random() * 256);
    //pick a "green" from  0 -255
    var g = Math.floor(Math.random() * 256);
    //pick a "blue" from  0 -255
    var b = Math.floor(Math.random() * 256);
    return "rgb(" + r + ", " + g + ", " + b + ")";
}
