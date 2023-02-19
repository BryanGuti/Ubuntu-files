// DOM ELEMENTS

const canvas = document.querySelector('#game');
const game = canvas.getContext('2d');
const buttons = document.querySelectorAll('.buttons > img');
const life = document.querySelector('#lifes');
const messageBox = document.querySelector('.message-box');
const continueBox = document.querySelector('.message-box .continue');
const gameOverMsg = document.querySelector('.message-box .game-over');
const winMsg = document.querySelector('.message-box .win');
const time = document.querySelector('#time span');
const continueButtons = document.querySelectorAll('.button');

// GLOBAL VARIABLES

const x = 0.05;
const y = 0.12;
const gap = 0.09;
const font = gap - 0.012;
const mapSize = 10;
const key = {
  38: 'up',
  40: 'down',
  37: 'left',
  39: 'right',
}
const player = {
  positionX: null,
  positionY: null,
  coordinateX: null,
  coordinateY: null,
}
const mapsLength = newMaps.length;

let level = 1;
let lifes = 5;
let hasLost = false;
let continueMsg = false;
let hasEnded = false;
let hasStop = false;
let map;
let isStart;
let hasExploded;
let width;
let lastEmoji;
let heightBox;
let idInterval;
let idSetTimeOut;
let timeStart;
let currentTime;

// GAME FUNCTIONS

function startGame() {
  if(!idInterval && !hasEnded) {
    timeStart = Date.now();
    idInterval = setInterval(printTime, 100);
  }
  if(isStart === undefined){
    window.addEventListener('resize', responsiveGame);
    printLifes();
  }

  if (lifes <= 0 || level > mapsLength) return;

  isStart = true;
  hasExploded = false;
  idSetTimeOut = false;
  hasStop = false;
  map = newMaps[level - 1];
  lastEmoji = 'Player';
  responsiveGame();

  window.addEventListener('keyup', movePlayer);
  buttons.forEach( button => {
    button.addEventListener('click', movePlayer);
  });
}

function printTime() {
  currentTime = Date.now() - timeStart;
  let hour, minute, second, cs;
  cs = parseInt(currentTime / 10);
  // if (parseInt(currentTime / 10))
  second = parseInt(cs / 100);
  cs = cs % 100;
  minute = parseInt(second / 60);
  second = second % 60;
  hour = parseInt(minute / 60);
  minute = minute % 60;
  time.innerText = `${hour}:${minute}:${second}:${cs}`;
}

function responsiveGame() {
  let windowWidth = window.innerWidth;
  let size;

  if (windowWidth <= 500) size = 0.85;
  else if (windowWidth <= 700) size = 0.6;
  else if (windowWidth <= 1000) size = 0.5;
  else size = 0.4;

  canvas.width = windowWidth * size;
  canvas.height = windowWidth * size;
  width = canvas.width;
  game.font = `${(font) * width}px Arial`;

  printGame();
}

function printMap() {
  let i, j, emoji;
  let mapX = x;
  let mapY = y;

  clearMap();

  for (i = 0; i < mapSize; i++) {
    for ( j = 0; j < mapSize; j++) {
      emoji = map[i][j]
      game.fillText(emojis[emoji], width * mapX, width * mapY);


      if (emojis[emoji] === '🚪' && isStart) {
        player.positionX = mapX;
        player.positionY = mapY;
        player.coordinateX = j;
        player.coordinateY = i;
        isStart = false;
      }

      mapX += gap;
    }
    mapY += gap;
    mapX = x;
  }
}

function movePlayer(event) {
  if (event.target.id === 'up' || key[event.keyCode] === 'up') moveUp();
  else if (event.target.id === 'down' || key[event.keyCode] === 'down') moveDown();
  else if (event.target.id === 'right' || key[event.keyCode] === 'right') moveRight();
  else if (event.target.id === 'left' || key[event.keyCode] === 'left') moveLeft();
  else return;

  printGame();
}

function moveUp() {
  if ((player.coordinateY - 1) < 0) return;

  player.positionY -= gap;
  player.coordinateY--;
}

function moveDown() {
  if ((player.coordinateY + 1) > (mapSize - 1)) return;

  player.positionY += gap;
  player.coordinateY++;
}

function moveRight() {
  if ((player.coordinateX + 1) > (mapSize - 1)) return;

  player.positionX += gap;
  player.coordinateX++;
}

function moveLeft() {
  if ((player.coordinateX -1) < 0) return;

  player.positionX -= gap;
  player.coordinateX--;
}

function clearMap() {
  game.clearRect(0, 0, width, width);
}

function printEmoji(emojiX, emojiY) {
  game.fillText(emojis[lastEmoji], width * emojiX, width * emojiY);
}

function clearEmoji(){
  game.clearRect(width * player.positionX, width * (player.positionY - font + 0.005), width * gap,width * gap);

}

function printPlayer() {
  if (!hasExploded && emojis[lastEmoji] !== '🎁') {
    printEmoji(player.positionX, player.positionY);
    return;
  }

  if (lifes <= 0) {
    lastEmoji = 'Lost';
    printGameOver();
  }

  if (level > mapsLength) {
    lastEmoji = 'Win';
    hasEnded = true;
  }

  if (hasEnded && idInterval) {
    buttons.forEach(button => {
      button.removeEventListener('click', movePlayer);
    });
    window.removeEventListener('keyup', movePlayer);
    clearInterval(idInterval);
    idInterval = undefined;
  }

  clearEmoji();
  printEmoji(player.positionX, player.positionY);

  if (hasExploded) {
    printLifes();
    hasStop = true;
  }

  if (hasStop && !idSetTimeOut) {
    buttons.forEach(button => {
      button.removeEventListener('click', movePlayer);
    });
    window.removeEventListener('keyup', movePlayer);

    idSetTimeOut = setTimeout(startGame, 1000);
    return;
  }

  if (emojis[lastEmoji] === '🎁') startGame();
}

function printGame() {
  printMap();
  if (emojis[lastEmoji] !== '💥') {
    lastEmoji = map[player.coordinateY][player.coordinateX];
  }
  if (emojis[lastEmoji] === ' ' || emojis[lastEmoji] === '🚪') {
    lastEmoji = 'Player';
    printPlayer();
  } else if (emojis[lastEmoji] === '💣️' && lifes > 0){
    lastEmoji = 'Collision';
    hasExploded = true;
    lifes--;
    printPlayer();
  } else if (emojis[lastEmoji] === '🎁') {
    level++;
    printPlayer();
  } else {
    printPlayer();
    return;
  }
}

function printLifes() {
  life.innerText = emojis['Heart'].repeat(lifes);
}

// function time() {

// }

// function bombGame() {

// }

function printGameOver() {
  if (!hasLost && !continueMsg) {
    clearInterval(idInterval);

    hasLost = true;
    gameOverMsg.style.display = 'block';
    messageBox.style.display = 'flex';

    setTimeout(() => {
      continueMsg = true;
      hasLost = false;
      gameOverMsg.style.display = 'none';
      continueBox.style.display = 'grid'
    }, 5000)
  }
  heightBox = window.getComputedStyle(messageBox).getPropertyValue('height');
  heightBox = Number(heightBox.replace('px', ''));
  messageBox.style.top = `calc(50vh - ${heightBox / 2}px)`;
}

// EVENTS

window.addEventListener('DOMContentLoaded', startGame);
