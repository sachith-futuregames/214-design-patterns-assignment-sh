[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment

The Game is a Cookie Clicker that moves the Cookie to a random space when cicked on. 
The Design patterns used for the assignment are SINGLETON and OBSERVER

Singleton:
the Class Delegate System is a Singleton class. The Delegate class was being used to fire delegate calls when an event occured. 
Teh DelegateSystem Class implements the singleton Pattern in the following way 
1. It can only have one instance
2. The Instance is globally accesible using the static GetInstance() function
3. The CopyConstructor has been deleted to allow for any further references to be created
4. The Default Constructor has been made private
5. The Static instance is private and can only be accessed by the GetInstance() function that ensures that no other instances exist of the class

THis pattern was used because it was imperative that there was only one delegatesystem in the Project. It allowed the System to be accessed globally so that the Observers could subscribe to it and the call to broadcast could be ade by any class 


Observer:
The Cookie and the TextRenderer class implement the Observer Class. They Subscribe to a source and when the makes the decision to broadcast a Broadcast() function is called on these classes
It was implemented using an Observer interface that required the class to implement the Broadcast Function 

This allowed a robust and loosely bound structure to be created in the Delegate System when broadcasting the Delegate 

![image](https://github.com/sachith-futuregames/214-design-patterns-assignment-sh/assets/113014784/a31b89f9-45ba-4168-b9e6-e4bce19264db)

![image](https://github.com/sachith-futuregames/214-design-patterns-assignment-sh/assets/113014784/2acbce07-391a-4aea-bc38-096a9b6031b0)


https://github.com/sachith-futuregames/214-design-patterns-assignment-sh/assets/113014784/d3c96828-56be-4261-9be6-447dce7e3d59

