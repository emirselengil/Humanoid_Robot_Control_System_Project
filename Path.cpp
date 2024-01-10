//152120211124 Alperen EVCÝ    19.12.2023

/**
 * @file Path.cpp
 * @brief Implementation of the Path class.
 */
#include "Path.h"

 /**
  * @brief Adds a Pose to the path.
  * @param pose The Pose to be added.
  */
void Path::addPos(Pose pose)
{
    Node* newNode = new Node(pose);  
    
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode; 
        tail = newNode;
    }
    number++; 
}

/**
 * @brief Prints the poses in the path.
 */
void Path::print()
{
    if (head == nullptr) {
        cout << "Path is Empty!" << endl;
    }                                                                    
    else {                                                               
        Node* Temp = head;                                               
        while (Temp != nullptr) {                                  
            cout << "(X): " << Temp->pose.getX() << endl;                
            cout << "(Y): " << Temp->pose.getY() << endl;                
            cout << "(Th): " << Temp->pose.getTh() << endl << endl;              
                                                                         
            Temp = Temp->next;                                           
        }                                                                
    }                                                             
    
}
/**
 * @brief Overloaded operator for accessing poses by index.
 * @param index The index of the pose to be accessed.
 * @return The Pose at the specified index.
 */
Pose Path::operator[](int index)
{
    if (index < 0 || index >= number)
    {
        cout << "Index out of bounds!" << endl;
        return Pose(); 
    }

    Node* current = head; 
    int count = 0;

    while (count < index)
    {
        current = current->next;
        count++;
    }

    return current->pose; 
}

/**
 * @brief Gets the Pose at the specified index.
 * @param index The index of the pose to be retrieved.
 * @return The Pose at the specified index.
 */
Pose Path::getPos(int index)
{
    return (*this)[index]; 
}

/**
 * @brief Removes the pose at the specified index.
 * @param i The index of the pose to be removed.
 * @return True if the removal is successful, false otherwise.
 */
bool Path::removePos(int i)
{
    if (i < 0 || i >= number) {
        cout << "Index out of bounds!" << endl;
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

   
    int j = 0;

   
    while (j < i) {
        previous = current;
        current = current->next;
        j++;
    }


    if (previous != nullptr) {
        // Not the first node
        previous->next = current->next;

        if (current == tail) {
            // If the removed node is the last node, update tail
            tail = previous;
        }

        delete current;
    }
    else {
        // Removing the first node
        head = current->next;

        if (head == nullptr) {
            // If the list becomes empty, update tail
            tail = nullptr;
        }
        delete current;
    }
    number--;
    return true;
}

/**
 * @brief Inserts a pose at the specified index.
 * @param i The index at which the pose is to be inserted.
 * @param pose The Pose to be inserted.
 * @return True if the insertion is successful, false otherwise.
 */
bool Path::insertPos(int i, Pose pose)
{
    if (i < 0 || i > number) {
        cout << "Index out of bounds!" << endl;
        return false;
    }

    Node* newNode = new Node(pose);

    if (i == 0) {
        // Insert at the beginning
        newNode->next = head;
        head = newNode;

        if (number == 0) {
            // If the list was empty, update tail
            tail = newNode;
        }
    }
    else if (i == number) {
        // Insert at the end
        tail->next = newNode;
        tail = newNode;
    }
    else {
        // Insert in the middle
        Node* current = head;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    number++;
    return true;
}
/**
 * @brief Gets the number of positions in the path.
 * @return The number of positions in the path.
 */
int Path::getNumber()
{
    return number;
}
/**
 * @brief Gets a string containing information about the path.
 * @return A string containing information about each position in the path.
 * If the path is empty, it returns "Path is Empty!".
 */
string Path::infos()
{
    string feedback = "";
    if (head == nullptr) {
        feedback += "Path is Empty!\n";
    }
    else {
        Node* Temp = head;
        while (Temp != nullptr) {
            feedback += "(X): " + to_string(Temp->pose.getX()) + "\n";
            feedback += "(Y): " + to_string(Temp->pose.getY()) + "\n";
            feedback += "(Th): " + to_string(Temp->pose.getTh()) + "\n";
            Temp = Temp->next;
        }
    }
    return feedback;
}

/**
 * @brief Overloaded output stream operator for printing the path.
 * @param o The output stream.
 * @param path The Path object to be printed.
 * @return The output stream.
 */
ostream& operator<<(ostream& o,Path& path) {
    path.print();   
    return o;
}

/**
 * @brief Overloaded input stream operator for adding a pose to the path.
 * @param i The input stream.
 * @param path The Path object to which the pose is to be added.
 * @return The input stream.
 */
istream& operator>>(istream& i, Path& path)
{
    Pose pose;  
    double x, y, th;
    cout << "Enter Pose (format: x y th): ";
    i >> x >> y >> th;
    pose.setX(x);
    pose.setY(y);
    pose.setTh(th);
    path.addPos(pose); 
     
    return i;
} 


