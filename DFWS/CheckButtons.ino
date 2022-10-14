char CheckButtons(TSPoint p) {

    for (uint8_t b = 0; b < 6; b++) { 
        if (category[b].contains(p.x, p.y)) {
            category[b].press(true); // tell the button it is pressed
            Serial.println("p.x inside b<6");
            Serial.println(p.x);

            if (b >= 0 && b <= 4) {


                //void fillscreen();
                //Create button for database
                if (b == 0) { // Fruit
                    categoryPage = 1;
                    tft.setRotation(0);
                    //DrawFruits();// Draw 
                    //Read button
                    /*for (uint8_t count = 0; count < 12; count++) // Number of 
                    {
                        if (fruit[count].contains(p.x, p.y)) {
                            fruit[count].press(true);
                             Serial.println(count);
                             Serial.println(p.x);
                        }
                        else {
                            fruit[count].press(false);
                        }
                    }*/

                    /*for (uint8_t count = 0; count < 12; count++) {

                        if (fruit[count].justReleased()) {
                            fruit[count].drawButton();

                        }

                        else if (fruit[count].justPressed()) {
                            fruit[count].drawButton(true);
                            //Serial.println(b);

                            if (count == 10) {// Back
                                currentPage = '0';
                                Serial.println("korik");
                                void fillscreen();
                                HomeScreen();
                            }
                            else {
                                Serial.println("Sayop");
                            }
                        }
                    }*/
                }
                else  if (b == 1) { //Veg
                    categoryPage = 2;
                    tft.setRotation(0);
                }
                else if (b == 2) { //Grains
                    categoryPage = 3;
                    tft.setRotation(0);
                }
                else if (b == 3) { //Protein
                    categoryPage = 4;
                    tft.setRotation(0);
                }
                else if (b == 4) { //Dairy
                    categoryPage = 5;
                    tft.setRotation(0);
                }
            }
        }
        else {
            category[b].press(false); // tell the button it is NOT pressed
        }
    }
}