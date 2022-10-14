
//Track
void DrawTrack(int goal, int intake, int rCal) {
    tft.fillScreen(ILI9341_BLACK);
    // create 'Title' for Tracker
    tft.drawRect(6, 7, 225, 50, ILI9341_CYAN);
    tft.fillRect(TRACKER_X, TRACKER_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(TRACKER_X, TRACKER_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.print("Tracker");

    //GOAL
    tft.fillRect(GOAL_X, GOAL_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(GOAL_X, GOAL_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Goal");

    tft.setCursor(24, 85);
    tft.setTextColor(ILI9341_BLUE, ILI9341_BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print(goal);

    //Intake
    tft.fillRect(In_X, In_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(In_X, In_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Intake");

    tft.setCursor(145, 85);
    tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print(intake);

    //Remaining Calories
    tft.fillRect(rCal_X, rCal_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(rCal_X, rCal_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Remaining Calories");

    tft.setCursor(95, 200);
    tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
    tft.setTextSize(4);
    //int goal1 = targetGoal(goal);
    tft.print(rCal);

    //Back Button
    BackButton[1].initButton(&tft, 55, 290, // x, y, w, h, outline, fill, text
        80, 30, ILI9341_CYAN, ILI9341_CYAN, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

    //Reset Button
    ResetButton[1].initButton(&tft, 185, 290, // x, y, w, h, outline, fill, text
        80, 30, ILI9341_RED, ILI9341_RED, ILI9341_BLACK,
        "Reset", 1.5);
    ResetButton[1].drawButton();
}

int SetTracker(int goal, int intake, int rCal) {
    int x = goal;
    int y = intake;
    int z = rCal;
    return x, y, z;
}

int RemainingCal(int intake, int rCal) {
    int rem = rCal - intake;
    return rem;
}