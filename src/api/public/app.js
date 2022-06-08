const shuffle = (array) => {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    const temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  return array;
};

const numbers = [...Array(75).keys()].map((index) => {
  index = index + 1;
  if (index <= 15) {
    return `B${index}`;
  } else if (index > 15 && index <= 30) {
    return `I${index}`;
  } else if (index > 30 && index <= 45) {
    return `N${index}`;
  } else if (index > 45 && index <= 60) {
    return `G${index}`;
  } else if (index > 60 && index <= 75) {
    return `O${index}`;
  }
});
console.log(numbers);

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

console.log("Bazingo!!!");
const main = document.getElementById("main");

const draws = shuffle(numbers);
main.innerHTML = "wooohooo";
(async () => {
  let history = '';
    for (let i = 0; i < draws.length; i++) {
    await sleep(3000);
    const id = `${draws[i].toLowerCase()}`;

    const tableCell = document.getElementById(id);
    console.log(tableCell);
    tableCell.style.backgroundColor = 'red';
    console.log(id);
    history = `<p>Call: ${i + 1}, Ball ${draws[i]}</p>\n`;
    main.innerHTML = history;
  }
})();
