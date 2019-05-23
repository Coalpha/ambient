#include <string.h>
#include <stdlib.h>
#include "coa_control.h"

#define c(code, str)  \
  case code:          \
  out->escaped = true; \
  out->data = str;     \
  break;              \

/// Visualizes control codes for a character
control_result* cesc(char it) {
  control_result* out = malloc(sizeof(control_result));
  switch (it) {
    c(0x00, "NUL");
    c(0x01, "SOH");
    c(0x02, "STX");
    c(0x03, "ETX");
    c(0x04, "EOT");
    c(0x05, "ENQ");
    c(0x06, "ACK");
    c(0x07, "BEL");
    c(0x08, "BS ");
    c(0x09, "HT ");
    c(0x0A, "LF ");
    c(0x0B, "VT ");
    c(0x0C, "FF ");
    c(0x0D, "CR ");
    c(0x0E, "SO ");
    c(0x0F, "SI ");
    c(0x10, "DLE");
    c(0x11, "DC1");
    c(0x12, "DC2");
    c(0x13, "DC3");
    c(0x14, "DC4");
    c(0x15, "NAK");
    c(0x16, "SYN");
    c(0x17, "ETB");
    c(0x18, "CAN");
    c(0x19, "EOM");
    c(0x1A, "SUB");
    c(0x1B, "ESC");
    c(0x1C, "FS ");
    c(0x1D, "GS ");
    c(0x1E, "RS ");
    c(0x1F, "US ");
    // c(0x7F, "DEL");
    // c(0x80, "PAD");
    // c(0x81, "HOP");
    // c(0x82, "BPH");
    // c(0x83, "NBH");
    // c(0x84, "IND");
    // c(0x85, "NEL");
    // c(0x86, "SSA");
    // c(0x87, "ESA");
    // c(0x88, "HTS");
    // c(0x89, "HTJ");
    // c(0x8A, "VTS");
    // c(0x8B, "PLD");
    // c(0x8C, "PLU");
    // c(0x8D, "RI ");
    // c(0x8E, "SS2");
    // c(0x8F, "SS3");
    // c(0x90, "DCS");
    // c(0x91, "PU1");
    // c(0x92, "PU2");
    // c(0x93, "STS");
    // c(0x94, "CCH");
    // c(0x95, "MW ");
    // c(0x96, "SPA");
    // c(0x97, "EPA");
    // c(0x98, "SOS");
    // c(0x99, "SGC");
    // c(0x9A, "SCI");
    // c(0x9B, "CSI");
    // c(0x9C, "ST ");
    // c(0x9D, "OSC");
    // c(0x9E, "PM ");
    // c(0x9F, "APC");
    default:
      out->escaped = false;
      out->data = &it;
      break;
  }
  return out;
}
#undef c

/// Visualizes control codes for a string 
control_result** sesc(char* it) {
  int len = strlen(it);
  control_result** out = malloc((len + 1) * sizeof(control_result));
  int i = 0;
  while (i < len) {
    out[i] = cesc(*(it + i));
    i++;
  }
  out[i] = NULL;
  return out;
}
