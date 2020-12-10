#include <iostream>
#include <conio.h>

using namespace std;

class DynamicStorage {
private:
	int templateInstance, defaultID;
	char letter;

public:
	DynamicStorage() {
		templateInstance = 0;
		defaultID = 1;
		letter = 'z';
	}

	void SetID(int num) { defaultID = num; }
	int GetID() { return defaultID; }

	void SetTemplateInstance(int num) { templateInstance = num; }
	int GetTemplateInstance() { return templateInstance; }

	void SetTemplateLetter(char let) { letter = let; }
	char GetTemplateLetter() { return letter; }
};

DynamicStorage *instance1;
DynamicStorage *instance2;
DynamicStorage *instance3;
DynamicStorage *mainStorePtr;

void ChangeStore(DynamicStorage *store1, DynamicStorage *store2, DynamicStorage *store3, DynamicStorage*& mainPtr);
void SetStore(DynamicStorage*& mainPtr);
void ShowStore(DynamicStorage *mainStore);

void ShowMenu() {
	int numInput = 0;
	cout << "Welcome to the Dynamic Storage Mechanism Subsystem!" << endl << endl;
	cout << "1 - Set values to current store." << endl;
	cout << "2 - Change current selected store." << endl;
	cout << "3 - Show current value store." << endl << endl;

	cin >> numInput;
	if(!mainStorePtr)
		cout << "Current store is pointing at nothing." << endl;

	switch(numInput) {
	case 1:
		SetStore(mainStorePtr);
		break;

	case 2:
		ChangeStore(instance1, instance2, instance3, mainStorePtr);
		break;

	case 3:
		ShowStore(mainStorePtr);
		break;
	}
}

void ChangeStore(DynamicStorage *store1, DynamicStorage *store2, DynamicStorage *store3, DynamicStorage*& mainPtr) {
	if(mainPtr)
		cout << "Current store value is " << mainPtr->GetTemplateInstance() << endl;

	int numInput = 0;
	cout << "What store would you like to use? (1-3 only)" << endl;
	cin >> numInput;

	switch(numInput) {
	case 1:
		mainPtr = store1;
		break;

	case 2:
		mainPtr = store2;
		break;

	case 3:
		mainPtr = store3;
		break;
	}

	cout << "New store value is " << numInput << endl << endl;
}

void SetStore(DynamicStorage*& mainPtr) {
	int numberInput = 0;
	char letterInput;
	cout << "Current store value to change is " << mainPtr->GetID() << endl;
	
	cout << "Enter new number." << endl;
	cin >> numberInput;
	mainPtr->SetID(numberInput);

	cout << "Enter new letter." << endl;
	cin >> letterInput;
	mainPtr->SetTemplateLetter(letterInput);
	
	cout << "New values have been set." << endl << endl;
}

void ShowStore(DynamicStorage *mainStore) {
	cout << "Current store value is " << mainStore->GetTemplateInstance() << endl;
	cout << "Store's number is " << mainStore->GetID() << endl;
	cout << "Store's letter is " << mainStore->GetTemplateLetter() << endl << endl;
}

int main() {
	instance1 = new DynamicStorage;
	instance2 = new DynamicStorage;
	instance3 = new DynamicStorage;

	instance1->SetTemplateInstance(1);
	instance2->SetTemplateInstance(2);
	instance3->SetTemplateInstance(3);

	instance3->SetID(15);
	instance3->SetTemplateLetter('c');

	char userInput;

	do {
		ShowMenu();
		cout << "Do you want to try again? (y/n)" << endl;
		cin >> userInput;
		cout << endl << endl;
	} while(userInput == 'y');

	cout << "Thank you!";

	getch();
	return 0;
}