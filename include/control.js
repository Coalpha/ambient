// https://www.compart.com/en/unicode/category/Cc
function a(text) {
  return `"${text}"`.padEnd(3, ' ');
}
console.log(
  [...document.querySelector("div.list-grid").children]
    .slice(1)
    .map(e => `c(0x${e.children[0].innerText.slice(-2)}, ${a(e.children[1].children[0].innerText)});`)
    .join('\n')
);
