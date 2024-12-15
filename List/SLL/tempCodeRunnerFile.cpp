while(current != nullptr) {
                if (current->data.getName() == name) {
                    cout << "Pls type your info again!\n";
                    cin >> current->data;
                    cout << "The info ontact has been changed\n";
                    break;
                }
                current = current->next;
                if (current == nullptr) {
                    cout << "The contact does not exsit!\n";
                    break;
                }
            }