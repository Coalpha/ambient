// See https://hyper.is#cfg for all currently supported options
const config = {
  shell:         "C:/Windows/System32/wsl.exe",
  shellArgs:     [],
  defaultSSHApp: false,
};
config.borderColor = "#323E4D";
config.backgroundColor = "#293340";
config.foregroundColor = "#CDD2E9";
const cursorColors = [
  "#C185A5", "#73659C", // Sunday
  "#F4EDC5", "#FAE06C", // Monday
  "#FBC25B", "#FFAF5A", // Tuesday
  "#ED7973", "#FE5E60", // Wednesday
  "#DD5080", "#F789BA", // Tuesday
  "#91b3e5", "#245EC1", // Friday
  "#7881DE", "#53509C", // Saturday
];
const randomColor = cursorColors[0 | Math.random() * cursorColors.length] + "69";
config.cursorColor = config.selectionColor = randomColor;
config.cursorAccentColor = config[
  `${parseInt(randomColor.slice(1), 16) > 0x999999 ? "back" : "fore"}groundColor`
];
const badColor = false;
const colors = {
  red:       "#F3566A",
  orange:    "#FEA758",
  yellow:    "#FEE868",
  green:     "#9AEFA9",
  cyan:      "#9BE8D5",
  blue:      "#6AAAEA",
  sky:       "#6CD2FF",
  purple:    "#BE86E3",
  pink:      "#F789BA",
  champagne: "#FFDDDD",
  grey:      "#546386",
};
function choose(good, bad) {
  return colors[badColor ? bad : good];
}
config.colors = {
  black:   config.backgroundColor,
  red:     "#F3566A",
  yellow:  "#FEA758",
  green:   "#4AEF89",
  cyan:    choose("cyan", "blue"),
  blue:    choose("blue", "purple"),
  magenta: choose("purple", "pink"),
};
if (!badColor) {
  Object.assign(config.colors, {
    white:        config.foregroundColor,
    lightRed:     "#F789BA",
    lightYellow:  "#FEE868",
    lightGreen:   "#BAF2C2",
    lightCyan:    "#9BE8D5",
    lightBlue:    "#4CB2FF",
    lightBlack:   "#546386",
    lightMagenta: "#BE86E3",
    lightWhite:   "#FFDDDD",
  });
}
Object.assign(config, {
  fontSize:          14,
  padding:           "12px 14px",
  showHamburgerMenu: false,
  fontFamily:        "Hack, Ubuntu Mono, monospace",
});
const paneNavigation = {
  hotkeys: {
    navigation: {
      up:    "ctrl+alt+up",
      down:  "ctrl+alt+down",
      left:  "ctrl+alt+left",
      right: "ctrl+alt+right",
    },
    permutation_modifier: "shift", // Added to jump and navigation hotkeys for pane permutation
    jump_prefix:          "ctrl+alt", // completed with 1-9 digits
    maximize:             "ctrl+alt+enter",
  },
};
module.exports = {
  config,
  paneNavigation,
  plugins:      ["hyperfullscreen", "hyper-pane"],
  localPlugins: [],
  keymaps:      {
    "tab:new": "alt+n",
  },
};
