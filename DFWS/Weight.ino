
//Weighing Scale

void DisplayWeight(int weight) {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(20, 30);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(4);
    tft.print(weight);
}

void OverWeight() {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(20, 30);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.print("Over Loaded");
}
