
//Dairy

void DrawDairy() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);


    tft.setCursor(10, 90);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Dairy");

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 2; col++) {
            fruit[col + row * 2].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, fruitcolors, ILI9341_WHITE,
                fruitlabels[col + row * 2], FRUIT_TEXTSIZE);
            fruit[col + row * 2].drawButton();
        }
    }

    BackButton[1].initButton(&tft, 40, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_ORANGE, ILI9341_ORANGE, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

    /*NextButton[1].initButton(&tft, 120, 290, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_YELLOW, ILI9341_YELLOW, ILI9341_BLACK,
        "Next", 1.5);
    NextButton[1].drawButton();*/

    NextButton[1].initButton(&tft, 200, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_RED, ILI9341_RED, ILI9341_BLACK,
        "Next", 1.5);
    NextButton[1].drawButton();

    CancelButton[0].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "CANCEL", SIDE_TEXTSIZE);
    CancelButton[0].drawButton();

    SaveButton[0].initButton(&tft, 200, 50, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "SAVE", SIDE_TEXTSIZE);
    SaveButton[0].drawButton();
}
