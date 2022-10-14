//Input
void DrawInput() {
    tft.fillScreen(ILI9341_DARKGREY);

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 3; col++) {
            i_buttons[col + row * 3].initButton(&tft, BUTTON_X_input + col * (BUTTON_W_input + BUTTON_SPACING_Xinput),
                BUTTON_Y_input + row * (BUTTON_H_input + BUTTON_SPACING_Yinput), // x, y, w, h, outline, fill, text
                BUTTON_W_input, BUTTON_H_input, ILI9341_WHITE, i_buttoncolors[col + row * 3],
                ILI9341_WHITE,
                i_buttonlabels[col + row * 3], BUTTON_TEXTSIZE_input);
            i_buttons[col + row * 3].drawButton();
        }
    }

    // create 'text field'
    tft.drawRect(TEXT_X_input, TEXT_Y_input, TEXT_W_input, TEXT_H_input, ILI9341_WHITE);
    tft.fillRect(STATUS_X, STATUS_Y, 240, 8, ILI9341_DARKGREY);
    tft.setCursor(STATUS_X, STATUS_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Enter Target Goal");

    //Save Button
    SaveButton[1].initButton(&tft, BUTTON_X_save, BUTTON_Y_save, // x, y, w, h, outline, fill, text
        BUTTON_W_save, BUTTON_H_save, ILI9341_GREEN, ILI9341_GREEN, ILI9341_WHITE,
        "Save", BUTTON_TEXTSIZE_input);
    SaveButton[1].drawButton();
}

void displayErrorGoal() {
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(2);
    tft.println("Invalid Input");
    tft.setCursor(50, 160);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(.5);
    tft.println("Calorie intake minimum");
    tft.setCursor(50, 170);
    tft.println("and maximum is between");
    tft.setCursor(25, 180);
    tft.println("1,200 and 2,000 calories per day");

    delay(5000);
    DrawInput();
}

int displayTargetGoal(int goal) {
    //tft.fillScreen(ILI9341_WHITE);
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("Target Goal is:");
    tft.setCursor(90, 180);
    tft.setTextSize(3);
    tft.println(goal);

    delay(2000);
    DrawInput();
}