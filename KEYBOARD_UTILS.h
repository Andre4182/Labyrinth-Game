#ifndef KEYBOARD_UTILS_H
#define KEYBOARD_UTILS_H

// scans the rows by setting the current row to a "LOW" pin value
void scanRow(int firstRow,int lastRow,int rowCounter) {
  for (int j = firstRow; j < (lastRow + 1); j++) {
    digitalWrite(j, HIGH);
  }
  digitalWrite(rowCounter, LOW); // switch on one row
}
//reads the column on the current set row and sets foundColumn to true if the current key is pressed, otherwise it increments the "noKey" parameter 
void readColumn(int *foundColumn,int *columnCounter,bool* foundCol,int* noKey) {
  *foundColumn = digitalRead(*columnCounter);
  if (*foundColumn == 0) {
    *foundCol = true;
  } else {
    *foundCol = false;
    *noKey = *noKey + 1; // counter for number of empty columns
  }
}


#endif