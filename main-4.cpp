#include <iostream>
#include <thread>
#include <string>

//Anywhere means mission control or the other far away launch pad.
static int totalRocketLaunchedFromAnywhere = 0;

//This will be the abort button/switch
static bool abortLaunchSwitch = false;

//prototype our functions
void LaunchRocketsFromRocketPad();



int main()
{
    //title of our program
    std::cout << "\n\n\n\t\t **** Welcome to Rocket Launcher!\n\n";
    //intro for user
    std::cout << "\nYou are a space cadet at the Main Space Institute.\n";
    std::cout << "\nThere is a launch pad far away from the base, which you will delegate launches to.\n";
    std::cout << "\nThere will be a Jr. space ranger named Jerry there at the launch pad with you.\n";
    std::cout << "\nAfter a single rocket launch, you will pass control onto Jerry for his training.\n";
    std::cout << "\nAfter 10 total rocket launches, you will have to abort any more rocket launches.\n";
    std::string enter = " ";
    std::cout << "\nPress enter to begin";
    std::getline(std::cin, enter);
    //system("read -p 'Press Enter to begin...' var");

    //Lets get the thread ID of our main and only thread at this point
    std::cout << "The Communication ID here at mission control is "<< std::this_thread::get_id() << std::endl;

    //Create our local rocket count and tracking variables
    int missionControlLaunchCount = 0;
    missionControlLaunchCount++;
    std::cout << "\nLaunch your rocket from mission control. " << std::flush;
    system("read -p 'Press Enter to launch...' var");
    std::cout << "\n\n\t\t\t****Mission control rocket #" << missionControlLaunchCount << " launched from mission control.****\n";
    std::cout << "\n\t\t\tInstitutes total launched rockets = " << ++totalRocketLaunchedFromAnywhere << std::endl;

    system("read -p 'Press Enter to pass control unto Jerry...' var");

    std::cout << "\n\t\t\t----Launch control has been given to Jerry----\n";
    std:: cout << "\nAgain, the communication ID here at mission control is "<< std::this_thread::get_id() << std::endl;

    std::cout << "\nRemember to hit abort after 10 rocket launches. Only you can abort any more launches.\n";
    std::thread rocketPadThread(LaunchRocketsFromRocketPad);
    system("read -p 'Press enter after #10 to abort.' var");
    //flip the abort launch switch to true.
    abortLaunchSwitch = true;
    std::cout << "\n\t\t\t----Abort has been initiated----\n";
    std::cout << "\nTo: Jr. Space Ranger Jerry! Abort launch switch has been flipped at mission control! Override has occurred. Step away from the launch terminal.\n";

    std::cout << "\n\nThe threads are about the be connected.";
    //we are about to join the thread
    rocketPadThread.join();


    std::cout << "\n\n\nThe communication threads has been joined!\n";
    std::cout << "\n\n\nNow ready to exit the training facility.\n\n\n";
    system("read -p 'Press Enter to exit.' var");

    return 0;
}

void LaunchRocketsFromRocketPad()
{
    //Lets us use the sleep to simulate time passing for processing
    using namespace std::literals::chrono_literals;
    int rocketPadLaunchCount = 0;
    //Lets identify if we are on a different thread by using the thread ID
    std::cout << "\nJerry has taken his position at the rocket pad, ready to launch his set of rockets.\n";
    std:: cout << "The communication ID at the rocket pad is "<< std::this_thread::get_id() << std::endl;

    //Let's have our jr. space cadet launch rockets at the launch pad
    while(abortLaunchSwitch != true) //reads "while the abortLaunchSwitch is not equal to true"
    {
        std::cout << "\n\t\t\t****Rocket pad rocket # " << ++rocketPadLaunchCount << " launched from the Rocket Pad.****\n";
        //remember the rocket base is made up of both the mission control launch facility and the launch pad facility
        std::cout << "\n\t\t\tInstitutes total launched rockets = " << ++totalRocketLaunchedFromAnywhere << std::endl;
        std::this_thread::sleep_for(3s);
    }
}
