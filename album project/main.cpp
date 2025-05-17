#include <iostream>
#include <string>

using namespace std;

// Cấu trúc đại diện cho một ảnh
struct Photo {
    string date;
    string description;
    Photo* next;
};

// Lớp quản lý album ảnh
class Album {
private:
    Photo* head;

public:
    Album() {
        head = nullptr;
    }

    // Thêm ảnh vào cuối danh sách
    void addPhoto(string date, string description) {
        Photo* newPhoto = new Photo{date, description, nullptr};
        if (!head) {
            head = newPhoto;
        } else {
            Photo* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newPhoto;
        }
        cout << "✅ Đã thêm ảnh.\n";
    }

    // Xóa ảnh theo mô tả
    void deletePhoto(string description) {
        Photo* temp = head;
        Photo* prev = nullptr;
        while (temp) {
            if (temp->description == description) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                cout << "🗑️  Đã xóa ảnh.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << " Không tìm thấy ảnh với mô tả đã nhập.\n";
    }

    // Hiển thị tất cả ảnh
    void displayAll() {
        if (!head) {
            cout << "📁 Album rỗng.\n";
            return;
        }

        cout << "Danh sách ảnh:\n";
        Photo* temp = head;
        while (temp) {
            cout << "- Ngày: " << temp->date << ", Mô tả: " << temp->description << endl;
            temp = temp->next;
        }
    }

    // Giải phóng bộ nhớ
    ~Album() {
        while (head) {
            Photo* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Hàm chính
int main() {
    Album album;
    int choice;
    string date, description;

    do {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Thêm ảnh\n";
        cout << "2. Xóa ảnh\n";
        cout << "3. Hiển thị tất cả ảnh\n";
        cout << "0. Thoát\n";
        cout << "============================\n";
        cout << "Chọn: ";
        cin >> choice;
        cin.ignore(); // Bỏ '\n' sau cin

        switch (choice) {
            case 1:
                cout << "Nhập ngày chụp: ";
                getline(cin, date);
                cout << "Nhập mô tả: ";
                getline(cin, description);
                album.addPhoto(date, description);
                break;
            case 2:
                cout << "Nhập mô tả ảnh muốn xóa: ";
                getline(cin, description);
                album.deletePhoto(description);
                break;
            case 3:
                album.displayAll();
                break;
            case 0:
                cout << " Thoát chương trình.\n";
                break;
            default:
                cout << " Lựa chọn không hợp lệ.\n";
        }

    } while (choice != 0);

    return 0;
}
