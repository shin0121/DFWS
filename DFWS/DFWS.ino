/*
 Name:		DFWS.ino
 Created:	10/5/2022 6:05:21 PM
 Author:	CABELIN
*/
//////////////////////////////////////////////////////////////// Everything important before the void setup

#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include <HX711_ADC.h> 
#include <Wire.h>


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 47;
const int LOADCELL_SCK_PIN = 46;

HX711_ADC scale(47, 46);
int taree = A0;

// Color definitions
#define ILI9341_BLACK 0000 /* 0, 0, 0 */
#define ILI9341_NAVY 0x000F /* 0, 0, 128 */
#define ILI9341_DARKGREEN 0x03E0 /* 0, 128, 0 */
#define ILI9341_DARKCYAN 0x03EF /* 0, 128, 128 */
#define ILI9341_MAROON 0x7800 /* 128, 0, 0 */
#define ILI9341_PURPLE 0x780F /* 128, 0, 128 */
#define ILI9341_OLIVE 0x7BE0 /* 128, 128, 0 */
#define ILI9341_LIGHTGREY 0xC618 /* 192, 192, 192 */
#define ILI9341_DARKGREY 0x7BEF /* 128, 128, 128 */
#define ILI9341_BLUE 0x001F /* 0, 0, 255 */
#define ILI9341_GREEN 0x07E0 /* 0, 255, 0 */
#define ILI9341_CYAN 0x07FF /* 0, 255, 255 */
#define ILI9341_RED 0xF800 /* 255, 0, 0 */
#define ILI9341_MAGENTA 0xF81F /* 255, 0, 255 */
#define ILI9341_YELLOW 0xFFE0 /* 255, 255, 0 */
#define ILI9341_WHITE 0xFFFF /* 255, 255, 255 */
#define ILI9341_ORANGE 0xFD20 /* 255, 165, 0 */
#define ILI9341_GREENYELLOW 0xAFE5 /* 173, 255, 47 */
#define ILI9341_PINK 0xF81F
#define ILI9341_esti 0x794379
#define ILI9341_esti2 0x86923B
/******************* UI details */
#define BUTTON_X 120
#define BUTTON_Y 140
#define BUTTON_W 220
#define BUTTON_H 40
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10
#define BUTTON_TEXTSIZE 2

// text box where numbers go
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_W 150
#define TEXT_H 80
#define TEXT_TSIZE 3
#define TEXT_TCOLOR ILI9341_MAGENTA
// the data (phone #) we store in the textfield
#define TEXT_LEN 4
char textfield[TEXT_LEN + 1] = "";
uint8_t textfield_i = 0;
#define YP A3 // must be an analog pin, use "An" notation!
#define XM A2 // must be an analog pin, use "An" notation!
#define YM 9 // can be a digital pin
#define XP 8 // can be a digital pin
#define TS_MINX 130
#define TS_MAXX 910
#define TS_MINY 80
#define TS_MAXY 900
// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 60

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

//int goal;

//button details for InputScreen
#define BUTTON_X_input 50
#define BUTTON_Y_input 120
#define BUTTON_W_input 60
#define BUTTON_H_input 30
#define BUTTON_SPACING_Xinput 10
#define BUTTON_SPACING_Yinput 10
#define BUTTON_TEXTSIZE_input 2
//Textbox Details for InputScreen
#define TEXT_X_input 10
#define TEXT_Y_input 10
#define TEXT_W_input 220
#define TEXT_H_input 50
#define TEXT_TSIZE_input 3
#define TEXT_TCOLOR_input ILI9341_MAGENTA
//SaveButton
#define BUTTON_X_save 120
#define BUTTON_Y_save 280
#define BUTTON_W_save 200
#define BUTTON_H_save 35
#define BUTTON_SPACING_Xsave 10
#define BUTTON_SPACING_Ysave 10

//Button Details for Side Buttons
#define SIDE_X 200
#define SIDE_Y 20
#define SIDE_W 75 //WIDTH
#define SIDE_H 25
#define SIDE_I 5
#define SIDE_TEXTSIZE 1
#define SIDE_SPACING_X 5
#define SIDE_SPACING_Y 5

// Button Details Food Category
#define CATEG_X 120
#define CATEG_Y 120
#define CATEG_W 220
#define CATEG_H 30
#define CATEG_SPACING_X 5
#define CATEG_SPACING_Y 5
#define CATEG_TEXTSIZE 2

// Button Details Fruit Category
#define FRUIT_X 60 //Left border
#define FRUIT_Y 120 //Top
#define FRUIT_W 105
#define FRUIT_H 25 //lower
#define FRUIT_I 10
#define FRUIT_SPACING_X 15
#define FRUIT_SPACING_Y 8
#define FRUIT_TEXTSIZE 1.6

//NextButton
#define FRUIT_X_next 120
#define FRUIT_Y_next 280
#define FRUIT_W_next 200
#define FRUIT_H_next 35
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10

//TRACKER
#define TRACKER_X 50
#define TRACKER_Y 20

//GOAL
#define GOAL_X 25
#define GOAL_Y 120

//INTAKE
#define In_X 140
#define In_Y 120

//REMAINING CALORIES
#define rCal_X 10
#define rCal_Y 250


bool buttonEnabled = true;
char currentPage, categoryPage, unit;
int newcurrent=0, current=0;
int x = 0, y = 0, z = 0;


Adafruit_GFX_Button i_buttons[12];
/* create 15 buttons, in classic candybar phone style */
char i_buttonlabels[12][5] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "Back", "9", "Clr" };
uint16_t i_buttoncolors[12] = { ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE,
ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE,
ILI9341_BLUE, ILI9341_LIGHTGREY, ILI9341_BLUE, ILI9341_RED };

Adafruit_GFX_Button SaveButton[1];

Adafruit_GFX_Button BackButton[1], NextButton[1], CancelButton[1];
Adafruit_GFX_Button inputButton[1];
Adafruit_GFX_Button tareButton[1];
Adafruit_GFX_Button trackButton[1];
Adafruit_GFX_Button ResetButton[1];

//Category Buttons
Adafruit_GFX_Button category[5];
char categorylabels[5][24] = { "Fruits","Vegetables","Grains", "Protein", "Dairy" };
uint16_t categorycolors[5] = { ILI9341_DARKGREY, ILI9341_RED, ILI9341_esti2, ILI9341_esti, ILI9341_PINK};

//Fruit Category Buttons
Adafruit_GFX_Button fruit[12];
char fruitlabels[10][24] = { "Apple","Avocado","Banana", "Durian", "Grape", "Guava", "Jackfruit", "Lemon","Lime","Mango" };
uint16_t fruitcolors = ILI9341_esti2;



void setup() {

    Serial.begin(9600);
    tft.reset();
    tft.begin(0x9341);
    tft.setRotation(0);


    //Serial.println("HomeScreen Display");

    HomeScreen();
    currentPage = '0';
    newcurrent = '0';

    //Serial.begin(57600);
    pinMode(taree, INPUT_PULLUP);
    scale.begin(); // start connection to HX711
    scale.start(1000); // load cells gets 1000ms of time to stabilize
    //Calibarate your LOAD CELL with 100g weight, and change the value according to readings
    scale.setCalFactor(228);

}

#define MINPRESSURE 50
#define MAXPRESSURE 1000


void loop() {

    scale.update();
    float w = scale.getData();
    if (w < 0)
    {
        w = w * (-1);
        //Serial.println("-");
        //Serial.println("-");
    }
    else
    {
        //Serial.println(" ");
        //Serial.println(" ");
    }

    //DisplayWeight(w);

    if (w >= 10000)
    {
        w = 0;
        OverWeight();
        delay(200);
    }

    if (digitalRead(taree) == LOW)
    {
        //lcd.setCursor(0, 1); // set cursor to secon row
        Serial.println("   Taring...    ");
        scale.start(1000);
        //lcd.setCursor(0, 1);
        Serial.println("                ");
    }

    //delay(100);
   

    digitalWrite(13, HIGH);
    TSPoint p = ts.getPoint();
    digitalWrite(13, LOW);
    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
        // scale from 0->1023 to tft.width
        p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
        p.y = (tft.height() - map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    }

    
    if (currentPage == '0') {

        //Serial.println("Clear Button");
        //Serial.println(clearButton[0].contains(p.x, p.y));
        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            inputButton[0].press(true);
            Serial.println("input button");
            DrawInput();
            currentPage = '2';
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            tareButton[0].press(true);
            Serial.println("tare button");
            currentPage = '3';
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 80 && p.y <= 100) {
            trackButton[0].press(true);
            Serial.println("track button");
            DrawTrack(x,y,z);
            currentPage = '4';
        }

        else {
            inputButton[0].press(false);
            tareButton[0].press(false);
            trackButton[0].press(false);

            for (uint8_t b = 0; b < 5; b++) {
                if (category[b].contains(p.x, p.y)) {
                    //Serial.print("Pressing: "); Serial.println(b);
                    category[b].press(true); // tell the button it is pressed
                    //Serial.println("p.x:");
                    //Serial.println(p.x);
                    //Serial.println("p.y");
                    //Serial.println(p.y);

                    if (b == 0) {
                        currentPage = '5';
                        tft.setRotation(0);
                        DrawFruits();
                        Serial.println("Fruits");
                    }
                    if (b == 1) {
                        currentPage = '6';
                        tft.setRotation(0);
                        DrawVeg();
                        Serial.println("Veg");
                    }
                    if (b == 2) {
                        currentPage = '7';
                        tft.setRotation(0);
                        DrawGrains();
                    }
                    if (b == 3) {
                        currentPage = '8';
                        tft.setRotation(0);
                        DrawProtein();
                    }
                    if (b == 4) {
                        currentPage = '9';
                        tft.setRotation(0);
                        DrawDairy();
                    }
                    else {
                        category[b].press(false); // tell the button it is NOT pressed
                    }
                }
            }
               
        }
    }

    //INPUT
    if (currentPage == '2') {

        //Serial.println("INSIDE!");
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].contains(p.x, p.y)) {
                i_buttons[b].press(true); // tell the button it is pressed
            }
            else {
                i_buttons[b].press(false); // tell the button it is NOT pressed
            }
        }
        // now we can ask the buttons if their state has changed
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].justReleased()) {
                i_buttons[b].drawButton(); // draw normal
            }

            if (i_buttons[b].justPressed()) {
                i_buttons[b].drawButton(true); // draw invert!

                // if a numberpad button, append the relevant # to the textfield
                if (b >= 0 && b != 9 && b != 11) {
                    if (textfield_i < TEXT_LEN) {
                        textfield[textfield_i] = i_buttonlabels[b][0];
                        textfield_i++;
                        textfield[textfield_i] = 0; // zero terminate
                    }
                }

                // clr button
                if (b == 11) {
                    textfield[textfield_i] = 0;
                    if (textfield > 0) {
                        textfield_i--;
                        textfield[textfield_i] = ' ';
                    }
                }

                if (textfield_i == 255) {
                    //Serial.print("THIS IS 255  ");
                    //Serial.println(textfield_i);
                    textfield_i = 0;
                }

                // update the current text field
                Serial.println(textfield);
                tft.setCursor(TEXT_X + 2, TEXT_Y + 10);
                tft.setTextColor(ILI9341_BLACK, ILI9341_DARKGREY);
                tft.setTextSize(TEXT_TSIZE);
                tft.print(textfield);

                //Back Button
                if (b == 9) {
                    currentPage = '0';
                    textfield_i = 0;
                    void fillscreen();
                    HomeScreen();
                }

                //delay(100); // UI debouncing
            }
        }

        if (p.x >= 120 && p.x <= 320 && p.y >= 280 && p.y <= 315) {
            Serial.println("save button");

            //strcpy(textfield, textfield);
            x = atoi(textfield);
            Serial.println(x);

            if (x < 1200 || x > 2000 ) {
                displayErrorGoal();
                textfield_i = 0;
                x = 0;
                y = 0;
                z = 0;
            }
            else {
                Serial.println(x);
                y = 0;
                z = 0;
                SetTracker(x, y, z);
                textfield_i = 0;
                displayTargetGoal(x);
                          
            }

            
        }
          
     
    }

    
    if (currentPage == '3') {
        DrawTare();
    }

    //Tracker
    if (currentPage == '4') {

        //Serial.println("Inside Tracker!");
        if (BackButton[1].contains(p.x, p.y)) {
            BackButton[1].press(true); // tell the button it is pressed
        }
        else {
            BackButton[1].press(false); // tell the button it is NOT pressed
        }
        //Serial.println("Page 4");
        if (BackButton[1].justReleased()) {
            BackButton[1].drawButton(); // draw normal
        }

        if (BackButton[1].justPressed()) {
            BackButton[1].drawButton(true);
            //if (BackButton[1].isPressed()){
            currentPage = '0';
            void fillscreen();
            HomeScreen();

        }

        if (ResetButton[1].contains(p.x, p.y)) {
            ResetButton[1].press(true); 
        }
        else {
            ResetButton[1].press(false);
        }
        
        if (ResetButton[1].justReleased()) {
            ResetButton[1].drawButton(); 
        }

        if (ResetButton[1].justPressed()) {
            ResetButton[1].drawButton(true);
            Serial.println("reset button");
            x = 0;
            y = 0;
            z = 0;
            Serial.println(x);
            Serial.println(y);
            Serial.println(z);
            SetTracker(x, y, z);
            DrawTrack(x, y, z);

        }
    }
    //Fruits
    if (currentPage == '5') {
        
        Serial.println("Fruits");

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            CancelButton[0].press(true);
            Serial.println("cancel button");
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            SaveButton[0].press(true);
            Serial.println("save button");
        }
        if (p.x >= 40 && p.x <=100 && p.y>=295 && p.y<=325) {
            Serial.println("back button");
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            CancelButton[0].press(false);
            SaveButton[0].press(false);
            BackButton[0].press(false);
        }


    }
    //Veg
    if (currentPage == '6') {
        Serial.println("Veg");

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            CancelButton[0].press(true);
            Serial.println("cancel button");
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            SaveButton[0].press(true);
            Serial.println("save button");
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            CancelButton[0].press(false);
            SaveButton[0].press(false);
            BackButton[0].press(false);
        }
    }
    //Grains
    if (currentPage == '7') {
        Serial.println("Grains");

        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            CancelButton[0].press(true);
            Serial.println("cancel button");
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            SaveButton[0].press(true);
            Serial.println("save button");
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            CancelButton[0].press(false);
            SaveButton[0].press(false);
            BackButton[0].press(false);
        }
    }
    //Protein
    if (currentPage == '8') {
        Serial.println("Protein");
        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            CancelButton[0].press(true);
            Serial.println("cancel button");
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            SaveButton[0].press(true);
            Serial.println("save button");
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            CancelButton[0].press(false);
            SaveButton[0].press(false);
            BackButton[0].press(false);
        }
    }
    //Dairy
    if (currentPage == '9') {
       
        if (p.x >= 200 && p.x <= 275 && p.y >= 20 && p.y <= 40) {
            CancelButton[0].press(true);
            Serial.println("cancel button");
        }
        if (p.x >= 200 && p.x <= 275 && p.y >= 50 && p.y <= 70) {
            SaveButton[0].press(true);
            Serial.println("save button");
        }
        if (p.x >= 40 && p.x <= 100 && p.y >= 295 && p.y <= 325) {
            currentPage = '0';
            void fillscreen();
            HomeScreen();
        }
        else {
            CancelButton[0].press(false);
            SaveButton[0].press(false);
            BackButton[0].press(false);
        }
    }

}




void CheckInput(TSPoint p)
{
    Serial.println("INSIDE");
    // go thru all the buttons, checking if they were pressed
 
}
