// Một số thao tác của danh sách liên kết :
//     - Khởi danh danh sách 
//     - Tạo một  node của danh sách
//     - Thêm một phần tử đầu , cuối và sau một phần tử chỉ định cho danh sách
//     - Duyệt danh sách
//     - Tìm kiếm phần tử trong danh sách
//     - Xóa một phần tử đầu , cuối và sau một phần tử chỉ định cho danh sách
//     - Xóa tất cả các phần tử trong danh sách

//     - Sắp xếp danh sách liên kết (Bubble Sort) O(n²)
//     -  Đảo ngược danh sách liên kết
//     - Tìm phần tử giữa danh sách liên kết
//     - Kiểm tra danh sách liên kết có chu trình không
//     -  Hợp hai danh sách liên kết đã sắp xếp thành một danh sách liên kết
//     - Xóa các phần tử trùng nhau trong danh sách liên kết đã sắp xếp
//     - Tách danh sách liên kết thành danh sách chẵn và lẻ
//      - Kiểm tra danh sách có đối xứng không (Palindrome)
//     - Xoay danh sách liên kết sang phải (Rotate List)
//     - Xóa node nhưng chỉ có con trỏ của nó
//     - Phát hiện và loại bỏ chu trình trong danh sách liên kết
//      - Tách danh sách liên kết theo giá trị X
//     - Gộp nhiều danh sách liên kết đã sắp xếp (Merge K Sorted Lists)
//      - Xóa node có giá trị lớn hơn node bên phải
//      -  Nhân hai số nguyên lớn biểu diễn dưới dạng danh sách liên kết



#include <iostream>
using namespace std;

// Khởi tạo danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Hàm khởi tạo danh sách rỗng, tránh giá trị rác
void init(Node*& head) {
    head = NULL;
}

// Tạo một node của danh sách
Node* createNode(int value) { // Sửa tên hàm và kiểu trả về
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm một phần tử đầu
void addFirst(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}


// Thêm một phần tử vào cuối
void addLast(Node*&head , int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }else{
        Node*p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}
// Thêm một phần tử sau một phần tử chỉ định
void addAfter(Node*& head, int value, int afterValue) {
    Node * newNode = createNode(value);
    Node * p = head;
    while(p != NULL && p->data != afterValue){
        p = p->next;
    }
    if(p != NULL){
        newNode->next = p->next;
        p->next = newNode;
    } else {
        cout << "Khong tim thay gia tri " << afterValue << " trong danh sach." << endl;
    }
}
// Duyệt danh sách
void output(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << "\t";
        p = p->next;
    }
}
//Tìm kiếm phần tử trong danh sách
Node* search(Node* head , int value){
    Node * p = head;
    while(p != NULL){
        if(p->data == value){
            return p;
        }
        p = p->next;
    }   
    return NULL;
}
//Xóa một phần tử đầu
void deleteFirst(Node*& head) {
    if(head!=NULL){
        Node *p = head;
        head = p->next;
        p->next = NULL;
        delete(p);
    }
}
// xóa phần tử cuối cùng
void deleteLast(Node*head){
    if(head == NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }

    if(head->next == NULL){
        delete(head);
        head = NULL;
        cout<<"Danh sach xoa thanh cong phan tu va tro thanh rong" <<endl;
        return;
    }

    Node * current = head;
    Node * previous = NULL;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    delete(current);

}
//xóa phần tử tìm kiếm trong dánh sách liên kết
void deleteNode(Node* &head,int v){
    if(head == NULL){
        cout<<"Danh sach rong"<<endl;
        return ;
    }else{
        Node *p = head;
        Node *prev = NULL;

        while(p != NULL && p->data != v){
            prev = p;
            p = p->next;
        }

        if(p==NULL){
            cout<<"Khong tim thay du lieu can xoa" << endl;
        }else{
            if(p == head){
                head = head -> next;
                delete(p);
            }else{
                prev->next = p->next;
                delete(p);
            }
        }
    }
}
// xoa tat ca
void deleteAllNode(Node* &head){
    while(head != NULL){
        deleteFirst(head);
    }
}


int main() {
    // Khai báo và khởi tạo danh sách
    Node* head;
    init(head);
    addLast(head,40);
    addFirst(head, 10); // Truyền head vào hàm addFirst
    addFirst(head, 20); // Truyền head vào hàm addFirst
    addFirst(head, 30); // Truyền head vào hàm addFirst
    addAfter(head,30000,20);
    addAfter(head,40000,10);

    
    //deleteFirst(head);
    //deleteLast(head);
    //deleteNode(head,40);
    //deleteAllNode(head);




    // Kiểm tra danh sách có rỗng không
    if (head == NULL) {
        cout << "Danh sach lien ket rong" << endl;
    } else {
        cout << "Danh sach lien ket la : " << endl;

        // tìm kiếm 
        int searchValue = 30;
        Node* result = search(head, searchValue);
        if(result){
            cout <<"Tim thay phan tu la :" << searchValue << endl;
        }else{
            cout << "Khong tim thay phan tu " << searchValue << endl;
        }


        //Duyệt danh sách
        output(head);
    }
    return 0;
}