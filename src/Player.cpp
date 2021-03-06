#include "../header/Player.h"

Player::Player(int m, int s, int e, const string& n) {
    math = m;
    science = s;
    english = e;
    name = n;
    dayNumber = weekNumber = 1;
}

void Player::randomEvent() {
    RandomEvent event;
    int number = event.getEventNumber();

    switch(number) {
        case 1:
            cout << "You fell and hit your head: -5 in math, science, and english." << endl << endl;
            math -= 5;
            science -= 5;
            english -= 5;
            if (math < 0) { math = 0; }
            if (science < 0) { science = 0;}
            if (english < 0) { english = 0;}
            break;
        case 2:
            cout << "You were invited to go out to eat. You lose sleep and some points in math, science, and english." << endl << endl;
            rest -= 10;
            math -= 5;
            science -= 5;
            english -= 5;
            if (rest < 0) rest = 0;
            if (math < 0) math = 0;
            if (science < 0) science = 0;
            if (english < 0) english = 0;
            break;
        case 3:
            cout << "You had an emergency outside of school. You keep up with your studies but lose sleep and forget to eat." << endl << endl;
            rest -= 15;
            food -= 10;
            math += 5;
            science += 5;
            english += 5;
            if (rest < 0) rest = 0;
            if (food < 0) food = 0;
            if (math > 100) math = 100;
            if (science > 100) science = 100;
            if (english > 100) english = 100;
            break;
        case 4:
            cout << "You applied for an internship and got accepted. You learn a lot of new things but lose sleep to keep up with everything." << endl << endl;
            math += 10;
            science += 10;
            english += 10;
            rest -= 10;
            if (math > 100) math = 100;
            if (science > 100) science = 100;
            if (english > 100) english = 10;;
            if (rest < 0) rest = 0;
            break;
        case 5:
            cout << "You went out to a party and got drunk. You decide to sleep in which causes you to miss class." << endl << endl;
            rest += 15;
            math -= 5;
            science -= 5;
            english -= 5;
            if (rest > 100) rest = 100;
            if (math < 0) math = 0;
            if (science < 0) science = 0;
            if (english < 0) english = 0;
            break;
        case 6:
            cout << "You went to class and there was a pop quiz.";
            if (calcSchoolLevel() >= 70) {
                cout << " You managed to pass the quiz so you don't have to spend extra time studying." << endl << endl;
            }
            else {
                cout << " You failed the quiz so you have to stay behind and study." << endl << endl;
                int t = (70 - calcSchoolLevel())/5 + 1;
                study(t);
            }
            break;
        default:
            cout << "Luckily, nothing happened to you today." << endl << endl;
            break;
    }
}

void Player::checkTime() {
    if (time <= 0) {
        cout << endl << "There is no more time left for today. Starting the next day." << endl;
        time = 24;
        if (dayNumber == 5) {
            dayNumber = 1;
            ++weekNumber; 
        }
        else 
            ++dayNumber;
        if (weekNumber <= 10) {
            cout << "It is now ";
            getDayAndWeek();
            cout << endl;
        }
    }
    else return;
}

void Player::checkTime(ostream& out) {
    if (time <= 0) {
        out << endl << "There is no more time left for today. Starting the next day." << endl;
        time = 24;
        if (dayNumber == 5) {
            dayNumber = 1;
            ++weekNumber; 
        }
        else 
            ++dayNumber;
        if (weekNumber <= 10) {
            out << "It is now ";
            getDayAndWeek(out);
            out << endl;
        }
    }
    else return;
}

void Player::checkLowStats() {
    if (food < 50) {
        cout << endl << "You're too hungry. You have to eat to regain strength." << endl;
        eat();
    }
    else if (rest < 50) {
        cout << endl << "You're too sleepy. You have to sleep to not fall over while walking." << endl;
        int t = (50 - rest)/5 + 1;
        sleep(t);
    }
    else if (calcSchoolLevel() < 50) {
        cout << endl << "You're too dumb. You have to study so you're not dumb." << endl;
        int t = (50 - calcSchoolLevel())/5 + 1;
        study(t);
    }
}

void Player::checkLowStats(ostream& out) {
    if (food < 50) {
        out << endl << "You're too hungry. You have to eat to regain strength." << endl;
        eat();
    }
    else if (rest < 50) {
        out << endl << "You're too sleepy. You have to sleep to not fall over while walking." << endl;
        int t = (50 - rest)/5 + 1;
        sleep(t);
    }
    else if (calcSchoolLevel() < 50) {
        out << endl << "You're too dumb. You have to study so you're not dumb." << endl;
        int t = (50 - calcSchoolLevel())/5 + 1;
        study(t);
    }
}

int Player::calcSchoolLevel() {
    school = (math + science + english)/3;
    if (school > 100) {
        school = 100;
        return 100;
    }
    else return (math + science + english)/3;
}

void Player::getDayAndWeek() {
    cout << "Day " << dayNumber << ", Week " << weekNumber;
}

void Player::getDayAndWeek(ostream& out) {
    out << "Day " << dayNumber << ", Week " << weekNumber;
}

void Player::getStats() {
    cout << "Name: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Time remaining: " << time << "/24" << endl;
    cout << "Food: " << food << "/100" << endl;
    cout << "Sleep: " << rest << "/100" <<endl;
    cout << "School: " << calcSchoolLevel() << "/100" << endl;
    cout << "Math: " << math << "/100" << endl;
    cout << "Science: " << science << "/100" << endl;
    cout << "English: " << english << "/100" <<endl;
}

void Player::getStats(ostream& out) {
    out << "Name: " << name << endl;
    out << "Major: " << major << endl;
    out << "Time remaining: " << time << "/24" << endl;
    out << "Food: " << food << "/100" << endl;
    out << "Sleep: " << rest << "/100" <<endl;
    out << "School: " << calcSchoolLevel() << "/100" << endl;
    out << "Math: " << math << "/100" << endl;
    out << "Science: " << science << "/100" << endl;
    out << "English: " << english << "/100" <<endl;
}

string Player::getName() {
    return name;
}

string Player::getMajor() {
    return major;
}

void Player::setName(const string& newName) {
    name = newName;
}

void Player::setStats(int f, int sl, int sc, int m, int s, int e) {
    if(f < 0 || sl < 0 || sc < 0 || m < 0 || s < 0 || e < 0) {
	throw "Cannot set stats with negative values!";
    }
    food = f;
    rest = sl;
    school = sc;
    math = m;
    science = s;
    english = e;
}

void Player::goToClass() {
    char answer = 'a';
    if (5 > time) {
        cout << "You do not have enough time in the day to study for the full time. You can only study for " << time << " hour(s)." << endl;
        while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
            cout << "Would you like to study for the remaining time? (Y/N): ";
            cin >> answer;
            if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                cout << "Please enter a valid answer." << endl;
        }
        if (answer == 'y' || answer == 'Y') {
            if (math <= (100 - 5 * time)) math += (5 * time);
            else math = 100;
            if (science <= (100 - 5 * time)) science += (5 * time);
            else science = 100;
            if (english <= (100 - 5 * time)) english += (5 * time);
            else english = 100;
            if (rest >= (2 * time)) rest -= (2 * time);
            else rest = 0;
            if (food >= (2 * time)) food -= (2 * time);
            else food = 0;
            cout << "You went to class for " << time << " hour(s)." << endl;
            cout << "Your math level is now " << math << "/100." << endl;
            cout << "Your science level is now " << science << "/100." << endl;
            cout << "Your english level is now " << english << "/100." << endl;
            time = 0;
        }
        else if (answer == 'n' || answer == 'N') {
            return;
        }
    }
    else {
        cout << "You studied for 5 hour(s)." << endl;
        if (math <= 75) math += 25;
        else math = 100;
        if (science <= 75) science += 25;
        else science = 100;
        if (english <= 75) english += 25;
        else english = 100;
        if (rest >= 10) rest -= 10;
        else rest = 0;
        if (food >= 10) food -= 10;
        else food = 0;
        time -= 5;
        cout << "Your math level is now " << math << "/100." << endl;
        cout << "Your science level is now " << science << "/100." << endl;
        cout << "Your english level is now " << english << "/100." << endl;
        cout << "You have " << time << " hour(s) left in the day." << endl;
    }
    checkTime();
    checkLowStats();
}

void Player::eat() {
    if (food <= 90) food += 10;
    else food = 100;
    if (rest >= 2) rest -= 2;
    else rest = 0;
    if (math >= 2) math -= 2;
    else math = 0;
    if (science >= 2) science -= 2;
    else science = 0;
    if (english >= 2) english -= 2;
    else english = 0;
    time -= 1;
    cout << "You ate for 1 hour." << endl;
    cout << "Your hunger level is now " << food << "/100." << endl;
    cout << "You have " << time << " hour(s) left in the day." << endl;
    checkTime();
    checkLowStats();
}

void Player::sleep(int t) {
    if (t < 0) {
        cout << "You can't gain time from sleeping." << endl;
        return;
    }
    char answer = 'a';
    if (t > time) {
        cout << "You do not have enough time in the day to sleep this much. You can only sleep for " << time << " hour(s)." << endl;
        while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
            cout << "Would you like to sleep? (Y/N): ";
            cin >> answer;
            if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                cout << "Please enter a valid answer." << endl;
        }
        if (answer == 'y' || answer == 'Y') {
            if (rest <= (100 - 5 * time)) rest += (5 * time);
            else rest = 100;
            if (food >= (2 * time)) food -= (2 * time);
            else food = 0;
            if (math >= (2 * time)) math -= (2 * time);
            else math = 0;
            if (science >= (2 * time)) science -= (2 * time);
            else science = 0;
            if (english >= (2 * time)) english -= (2 * time);
            else english = 0;
            cout << "You slept for " << time << " hour(s)." << endl;
            time = 0;
            cout << "Your rest level is now " << rest << "/100." << endl;
        }
        else if (answer == 'n' || answer == 'N') {
            return;
        }
    }
    else {
        cout << "You slept for " << t << " hour(s)." << endl;
        time -= t;
        if (rest <= (100 - 5 * t)) rest += (5 * t);
        else rest = 100;
        if (food >= (2 * t)) food -= (2 * t);
        else food = 0;
        if (math >= (2 * t)) math -= (2 * t);
        else math = 0;
        if (science >= (2 * t)) science -= (2 * t);
        else science = 0;
        if (english >= (2 * t)) english -= (2 * t);
        else english = 0;
        cout << "Your rest level is now " << rest << "/100." << endl;
        cout << "You have " << time << " hour(s) left in the day." << endl;
    }
    checkTime();
    checkLowStats();
}

void Player::study(int t) {
    if (t < 0) {
        cout << "You can't gain time from studying." << endl;
        return;
    }
    char answer = 'a';
    if (t > time) {
        cout << "You do not have enough time in the day to study this much. You can only study for " << time << " hour(s)." << endl;
        while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
            cout << "Would you like to study? (Y/N): ";
            cin >> answer;
            if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                cout << "Please enter a valid answer." << endl;
        }
        if (answer == 'y' || answer == 'Y') {
            if (math <= (100 - 5 * time)) math += (5 * time);
            else math = 100;
            if (science <= (100 - 5 * time)) science += (5 * time);
            else science = 100;
            if (english <= (100 - 5 * time)) english += (5 * time);
            else english = 100;
            if (rest >= (2 * time)) rest -= (2 * time);
            else rest = 0;
            if (food >= (2 * time)) food -= (2 * time);
            else food = 0;
            cout << "You studied for " << time << " hour(s)." << endl;
            time = 0;
            cout << "Your school level is now " << calcSchoolLevel() << "/100." << endl;
        }
        else if (answer == 'n' || answer == 'N') {
            return;
        }
    }
    else {
        cout << "You studied for " << t << " hour(s)." << endl;
        time -= t;
        if (math <= (100 - 5 * t)) math += (5 * t);
        else math = 100;
        if (science <= (100 - 5 * t)) science += (5 * t);
        else science = 100;
        if (english <= (100 - 5 * t)) english += (5 * t);
        else english = 100;
        if (rest >= (2 * t)) rest -= (2 * t);
        else rest = 0;
        if (food >= (2 * t)) food -= (2 * t);
        else food = 0;
        cout << "Your school level is now " << calcSchoolLevel() << "/100." << endl;
        cout << "You have " << time << " hour(s) left in the day." << endl;
    }
    checkTime();
    checkLowStats();
}

void Player::checkProgress() {
    double graduationPercent = (((static_cast<double>(weekNumber) - 1) * 5 + static_cast<double>(dayNumber))/50) * 100; 
    cout << "Graduation: " << setprecision(2) << fixed << graduationPercent << "% " << " complete." << endl;
    cout << "Condition to graduate: Complete all 50 days of school." << endl;

    double transferPercent = ((static_cast<double>(calcSchoolLevel()))/100) * 100;
    cout << endl << "Transfer: " << setprecision(2) << fixed << transferPercent << "% " << " complete." << endl;
    cout << "Condition to transfer: Have math, english, and science stats all at 100." << endl;
}
