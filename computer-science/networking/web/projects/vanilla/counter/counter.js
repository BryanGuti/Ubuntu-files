function startGame() {
  const buttons = Array.from(document.querySelectorAll('.arrow'));
  const number = document.querySelector('#number')

  buttons.forEach(button => {
    button.addEventListener('click', updateNumber)
  })
}

function updateNumber(event) {
  const action = event.target.id;
  let value = Number(number.textContent);
  console.log(action)
  if (action === 'add') {
    number.textContent = String(value + 1);
  }
  if (action === 'subtract') {
    number.textContent = String(value - 1);
  }
}


document.addEventListener('DOMContentLoaded', startGame)