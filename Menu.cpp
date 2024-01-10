//152120211066 Akýn BEKTAÞ  30.12.2023


/**
 * @brief Represents a menu interface for controlling a Nao robot.
 *
 * This class provides various menu options for interacting with the robot,
 * including connection management, motion control, and sensor information.
 */

#include "Menu.h"
/**
     * @brief Constructor for the Menu class.
     *
     * @param robot A pointer to the NaoRobotAPI instance.
     */
Menu::Menu(NaoRobotAPI* robot, RobotControl robControl) : robotAPI(robot), robControl(robControl) ,connected(false),access(false), password(0) {}

/**
     * @brief Clears the console screen.
     */
void Menu::screenClear()  
{
    system("cls");
}
/**
     * @brief Hides the console cursor.
     */
void Menu::hideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}
/**
     * @brief Moves the console cursor to the specified position.
     *
     * @param x The X-coordinate.
     * @param y The Y-coordinate.
     */
void Menu::cursorMovement(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/**
     * @brief Performs the animation for the main menu.
     */
void Menu::mainMenuAnimation()
{
    screenClear();
    hideCursor();

    string strings[8] = { "  Main Menu","1. Open Access","2. Close Access","3. Connection","4. Motion","5. Sensor","6. Path" ,"7. Quit"};

    for (int i = 0; i < 19; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 11; j++)
    {
        cursorMovement(63, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 19; i++)
    {
        cursorMovement(63 - i, 17);
        cout << bar;
    }
    for (int j = 0; j < 11; j++)
    {
        cursorMovement(44, 17 - j);
        cout << bar;
    }


    for (int i = 0; i < 8; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
        Sleep(300);
    }
    cursorMovement(x, y + 11);
    cout << "Choose One:";
}
/**
     * @brief Displays the main menu quickly without animation.
     */
void Menu::mainMenuFast()
{
    printAccessStatus();
    string strings[8] = { "  Main Menu","1. Open Access","2. Close Access","3. Connection","4. Motion","5. Sensor","6. Path" ,"7. Quit" };

    for (int i = 0; i < 19; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 11; j++)
    {
        cursorMovement(63, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 19; i++)
    {
        cursorMovement(63 - i, 17);
        cout << bar;
    }
    for (int j = 0; j < 11; j++)
    {
        cursorMovement(44, 17 - j);
        cout << bar;
    }


    for (int i = 0; i < 8; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];        
    }
    cursorMovement(x, y + 11);
    cout << "Choose One:";
}
/**
     * @brief Displays the connection menu.
     */
void Menu::connectionMenu()
{
    printAccessStatus();
    string strings[4] = { "  Connection Menu ","1. Connect Robot","2. Disconnect Robot","3. Back" };

    for (int i = 0; i < 24; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 7; j++)
    {
        cursorMovement(68, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 24; i++)
    {
        cursorMovement(68 - i, 13);
        cout << bar;
    }
    for (int j = 0; j < 7; j++)
    {
        cursorMovement(44, 13 - j);
        cout << bar;
    }

    for (int i = 0; i < 4; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
    }
    cursorMovement(x, y + 7);
    cout << "Choose One:";

    cin >> answer;
    int i = 0;

    while (answer > 3 || answer <= 0)
    {
        cursorMovement(x - 13, y + 10 + i);
        cout << "Please enter a positive integer between 1-4: ";
        i++;
        cin >> answer;
    }

    
    if (answer == 3)
    {
        menuOperations();            
    }
    else {
            if (answer == 1)
            {
                if (connected) {
                    screenClear();
                    cursorMovement(x + 5, y + 4);
                    cout << "Robot is already connected!!";
                    Sleep(3131);
                }
                else {
                    robotAPI->connect();
                    connected = true;
                    robControl.addSensor(bumperSensor);
                    robControl.addSensor(sonarSensor);
                    robControl.addSensor(forceSensor);
                    forceSensor->setSensorType();  
                    sonarSensor->setSensorType();
                    bumperSensor->setSensorType();
                    menuOperations();
                }
            }
            else if (answer == 2)
            {
                if (!connected) {
                    screenClear();
                    cursorMovement(x + 5, y + 4);
                    cout << "Robot is already disconnected!!";
                    Sleep(3131);
                }
                else {
                    robotAPI->disconnect();
                    connected = false;
                    menuOperations();
                }
            }

            menuOperations();
        }          
    
}
/**
     * @brief Displays the motion control menu.
     */
void Menu::motionMenu()
{
    string strings[9] = { "   Motion Menu ","1. Forward","2. Backward","3. Move Left","4. Move Right","5. Turn left","6. Turn Right","7. Stop","8. Back" };

    for (int i = 0; i < 22; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 13; j++)
    {
        cursorMovement(66, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 22; i++)
    {
        cursorMovement(66 - i, 19);
        cout << bar;
    }
    for (int j = 0; j < 13; j++)
    {
        cursorMovement(44, 19 - j);
        cout << bar;
    }

    for (int i = 0; i < 9; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
    }
    cursorMovement(x, y + 13);
    cout << "Choose One:";

    cin >> answer;
    int i = 0;

    while (answer > 8 || answer <= 0)
    {
        cursorMovement(x - 13, y + 10 + i);
        cout << "Please enter a positive integer between 1-4: ";
        i++;
        cin >> answer;
    }

    robControl.robotInterface->updateSensors();

    if (answer == 8)
    {
        menuOperations();
    }
    else {
        if (access) {
            if (connected) {
                if (!forceSensor->CheckFall()) {
                    if (answer == 1)
                    {
                        robControl.forward();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is moving forward...";
                        Sleep(9000);

                    }
                    else if (answer == 2)
                    {
                        robControl.backward();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is moving backward...";
                        Sleep(4000);
                    }
                    else if (answer == 3)
                    {
                        robControl.moveLeft();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is moving left...";
                        Sleep(6000);
                    }
                    else if (answer == 4)
                    {
                        robControl.moveRight();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is moving right...";
                        Sleep(6000);
                    }
                    else if (answer == 5)
                    {
                        robControl.turnLeft();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is turning left...";
                        Sleep(5000);
                    }
                    else if (answer == 6)
                    {
                        robControl.turnRight();
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot is turning right...";
                        Sleep(5000);
                    }
                    else if (answer == 7)
                    {
                        robControl.stop();
                    }

                    robControl.robotInterface->updateSensors();

                    if (forceSensor->CheckFall()) {
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "Robot fell during the operation... ";
                        Sleep(2000);
                    }
                    if (bumperSensor->checkTouch() && !forceSensor->CheckFall()) {
                        screenClear();
                        cursorMovement(x + 5, y + 4);
                        cout << "The robot touches an object ";
                        Sleep(2000);
                    }
                }
                else {
                    screenClear();
                    cursorMovement(x + 5, y + 4);
                    cout << "Robot fell, Robot can not move";
                    cursorMovement(x + 5, y + 6);
                    cout << "Wait a few seconds... ";
                    Sleep(3131);
                }
            }
            else {
                screenClear();
                cursorMovement(x + 5, y + 4);
                cout << "Robot is not connected!!";
                Sleep(3131);
            }
        }
        else {
            screenClear();
            cursorMovement(x + 5, y + 4);
            cout << "Access Denied!!";
            Sleep(3131);
        }
        
        menuOperations();
    }


}
/**
     * @brief Handles menu operations and user input.
     *
     * @return 0 when the user chooses to quit.
     */
int Menu::menuOperations()
{
    screenClear();
    if (connected) {
        robControl.print();       
    }
    mainMenuFast();    
    cin >> answer;
    int i = 0;

    while (answer > 7 || answer <= 0)
    {
        cursorMovement(x - 13 , y + 10 + i);
        cout << "Please enter a positive integer between 1-7: ";
        i++;
        cin >> answer;
    }

    
    if (answer == 7)
    {       
        return 0;
    }
    else {
        if (answer == 1) {                                            
            screenClear();                                            
            cursorMovement(x + 5, y + 6);                             
            if (access) {                                             
                cout << "You already have access";  
                Sleep(3000);
            }                                                         
            else {                                                    
                cout << "Open Access Password: ";                     
                cin >> password;                                      
                access = robControl.openAccess(password);             
                                                                      
                if (access) {                                         
                    cursorMovement(x + 10, y + 8);                     
                    cout << "Correct Password";
                    Sleep(3000);
                }                                                     
                else {                                                
                    cursorMovement(x + 10, y + 8);                     
                    cout << "Incorrect Password";
                    Sleep(3000);
                }                                                     
            }            
            menuOperations();
        }
        else if (answer == 2) {
            screenClear(); 
            cursorMovement(x + 5, y + 6);
            
            if (!access) {
                cout << "You already have not access";
                Sleep(3000);
            }
            else {
                cout << "Close Access Password: ";
                cin >> password;
                access = robControl.closeAccess(password); 

                if (!access) {
                    cursorMovement(x + 10, y + 8);
                    cout << "Correct Password";
                    cursorMovement(x + 10, y + 9);
                    cout << "Access Terminated";
                    Sleep(3000);
                }
                else {
                    cursorMovement(x + 10, y + 8);
                    cout << "Incorrect Password";
                    Sleep(3000);
                }
            }
            
            menuOperations(); 
        }
        else if (answer == 3)
        {
            screenClear();
            connectionMenu();
        }
        else if (answer == 4)
        {
            screenClear();
            motionMenu();
        }
        else if (answer == 5)
        {
            screenClear();
            sensorMenu();
        }
        else if (answer == 6) 
        {
            screenClear();
            pathMenu();
        }  
    }
}
/**
     * @brief Displays the sensor menu.
     */
void Menu::sensorMenu() {

    printAccessStatus();
    string strings[7] = { "  Sensor Menu ","1. Force Menu","2. Get Sonar Ranges","3. Check Touch","4. Record Sensor","5. Print Sensor","6. Back"};

    for (int i = 0; i < 24; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 10; j++)
    {
        cursorMovement(68, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 24; i++)
    {
        cursorMovement(68 - i, 16);
        cout << bar;
    }
    for (int j = 0; j < 10; j++)
    {
        cursorMovement(44, 16 - j);
        cout << bar;
    }

    for (int i = 0; i < 7; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
    }
    cursorMovement(x, y + 10);
    cout << "Choose One:";

    cin >> answer;
    int i = 0;

    while (answer > 6 || answer <= 0)
    {
        cursorMovement(x - 13, y + 10 + i);
        cout << "Please enter a positive integer between 1-6: ";
        i++;
        cin >> answer;
    }

    
    if (answer == 6)
    {           
        menuOperations(); 
    }
    else {
        if (connected) {
            if (answer == 1)
            {
                screenClear();
                forceMenu();
            }
            else if (answer == 2)
            {
                robControl.robotInterface->updateSensors();
                screenClear();
                cursorMovement(x - 10, y + 4);
                cout << "SONAR RANGES : (LEFT) " << sonarSensor->getRange(0) << " meters, (RIGHT) " << sonarSensor->getRange(1) << " meters";
                cursorMovement(x + 5, y + 6);
                cout << "Wait a few seconds... ";
                Sleep(5000);
            }
            else if (answer == 3) {
                robControl.robotInterface->updateSensors();
                screenClear();
                cursorMovement(x, y + 4);
                if (bumperSensor->checkTouch()) {
                    cout << "The robot touches an object";
                }
                else {
                    cout << "The robot does not touch an object";
                }
                cursorMovement(x + 5, y + 6);
                cout << "Wait a few seconds... ";
                Sleep(5000);
            }
            else if(answer == 4)
            {   
                screenClear();
                cursorMovement(x - 17, y + 4);
                cout << "Please Type a sensor name to record (bumper,sonar,force,etc..): ";
                string name;
                cin >> name;
                for (auto& i : name) i = tolower(i);
                cursorMovement(x + 5, y + 6);
                if (robControl.recordSensor(name)) {
                    cout << "Sensor has recorded to file...";
                    Sleep(3000);
                } 
                Sleep(3000); 
            }
            else if (answer == 5)
            {
                screenClear();
                cursorMovement(x - 17, y + 4);
                cout << "Please Type a sensor name to print (bumper,sonar,force,etc..): ";
                string name;
                cin >> name;
                for (auto& i : name) i = tolower(i);
                if (name == "bumper") {
                    cursorMovement(x-40, y + 6);
                    robControl.printSensor(name); 
                }
                else {
                    cursorMovement(x + 5, y + 6);
                    robControl.printSensor(name);                    
                }
                Sleep(3000);
            }

        }
        else {
            screenClear();
            cursorMovement(x + 5, y + 4);
            cout << "Robot is not connected!!";
            Sleep(3131);
        }
        menuOperations();  
    }
        
    
}
/**
     * @brief Displays the force menu.
     */
void Menu::forceMenu() { 
        
    printAccessStatus();
    string strings[4] = { "  Force Menu ","1. Get Force","2. Check Fall","3. Back" };

    for (int i = 0; i < 24; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 8; j++)
    {
        cursorMovement(68, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 24; i++)
    {
        cursorMovement(68 - i, 14);
        cout << bar;
    }
    for (int j = 0; j < 8; j++)
    {
        cursorMovement(44, 14 - j);
        cout << bar;
    }

    for (int i = 0; i < 4; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
    }
    cursorMovement(x, y + 8);
    cout << "Choose One:";

    cin >> answer;
    int i = 0;

    while (answer > 3 || answer <= 0)
    {
        cursorMovement(x - 13, y + 10 + i);
        cout << "Please enter a positive integer between 1-4: ";
        i++;
        cin >> answer;
    }

    
    if (answer == 3)
    {
        screenClear();
        sensorMenu();
    }
    else {
        if (answer == 1)
        {
            screenClear();
            cursorMovement(x, y + 4); 
            robControl.robotInterface->updateSensors();            
            cout << "Foot force of robot: " << forceSensor->getForce();
            cursorMovement(x + 4, y + 6);
            cout << "Wait a few seconds... ";
            Sleep(5000);
        }
        else if (answer == 2)
        {

            screenClear();
            cursorMovement(x, y + 4); 
            robControl.robotInterface->updateSensors();
            if (forceSensor->getForce() < 4) {
                cursorMovement(x + 6, y + 4);
                cout << "Robot fell... ";
            }
            else {
                cursorMovement(x + 7, y + 4);
                cout << "Robot standing... ";
            }
            cursorMovement(x + 4, y + 6);
            cout << "Wait a few seconds... ";
            Sleep(5000);
    
        }
        menuOperations(); 
    }
        
    
}
/**
    * @brief Displays the menu for managing the robot's path.
    * @details This function allows the user to interact with the robot's path,
    * including adding poses, clearing the path, and recording it to a file.
    */
void Menu::pathMenu() {

    printAccessStatus();
    string strings[5] = { "   Path Menu ","1. Add To Path","2. Clear Path","3. Record Path To File","4. Back"};

    for (int i = 0; i < 27; i++)
    {
        cursorMovement(44 + i, 6);
        cout << bar;
    }
    for (int j = 0; j < 8; j++)
    {
        cursorMovement(71, 6 + j);
        cout << bar;
    }
    for (int i = 0; i < 27; i++)
    {
        cursorMovement(71 - i, 14);
        cout << bar;
    }
    for (int j = 0; j < 8; j++)
    {
        cursorMovement(44, 14 - j);
        cout << bar;
    }

    for (int i = 0; i < 5; i++)
    {
        cursorMovement(x, y + i);
        cout << strings[i];
    }
    cursorMovement(x, y + 8);
    cout << "Choose One:";

    cin >> answer;
    int i = 0;

    while (answer > 5 || answer <= 0)
    {
        cursorMovement(x - 13, y + 10 + i);
        cout << "Please enter a positive integer between 1-5: ";
        i++;
        cin >> answer;
    }

    robControl.robotInterface->updateSensors();

    if (answer == 4)
    {
        menuOperations();
    }
    else {
        if (connected) {
           
            if (answer == 1)
            {
                robControl.addToPath();
                screenClear();
                cursorMovement(x + 5, y + 4);
                cout << "Position added to path...";
                Sleep(3000);

            }
            else if (answer == 2)
            {
                robControl.clearPath();
                screenClear();
                cursorMovement(x + 5, y + 4);
                cout << "Positions in path are cleared... ";
                Sleep(3000);
            }
            else if (answer == 3)
            {
                robControl.recordPathToFile();
                screenClear();
                cursorMovement(x + 5, y + 4);
                cout << "Path informations have been recorded to file...";
                Sleep(3000);
            }
            else if (answer == 4)
            {
                screenClear();
                menuOperations();
            }
        }
        else {
            screenClear();
            cursorMovement(x + 5, y + 4);
            cout << "Robot is not connected!!";
            Sleep(3131);
        }
        menuOperations();
    }


}
/**
    * @brief Prints the current access status of the robot.
    * @details This function displays whether the robot currently has access or not.
    */
void Menu::printAccessStatus() {
    cursorMovement(x + 53, 2);
    cout << "Access Status: "+ to_string(access);

    for (int i = 0; i < 18; i++)
    {
        cursorMovement(x + 52 + i, 0);
        cout << "*";
    }
    for (int j = 0; j < 3; j++)
    {
        cursorMovement(x + 51, 1 + j);
        cout << "|";
    }
    for (int i = 0; i < 18; i++)
    {
        cursorMovement(x + 69 - i, 4);
        cout << "*";
    }
    for (int j = 0; j < 3; j++)
    {
        cursorMovement(x + 70, 3 - j);
        cout << "|";
    }
}