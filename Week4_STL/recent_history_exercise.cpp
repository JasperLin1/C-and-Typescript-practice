#include <iostream>
#include <string>

// ========================================================
// 🎯 實戰練習：網站瀏覽歷史紀錄器 (RecentHistory)
// ========================================================
// 想像你在開發一個購物網站，你需要記錄使用者的兩種數據：
// 1. 最近瀏覽過的「網頁網址 (URL)」 ➡️ 這是一串字串 (std::string)
// 2. 最近瀏覽過的「商品編號 (ID)」  ➡️ 這是一個整數 (int)
//
// 為了不重複寫兩個類似的類別，請設計一個模板類別 `RecentHistory<T>`！
//
// 規格要求：
// - 成員變數：
//   - `T* arr` (動態陣列指標，儲存歷史紀錄)
//   - `int capacity` (最大容量)
//   - `int count` (目前已記錄的數量)
//
// - 成員函式：
//   - 建構子：接收 `cap` 並動態配置大小為 cap 的 T 陣列。
//   - 解構子：釋放動態記憶體。
//   - `void add(T item)`: 將新紀錄加入陣列中。如果滿了 (count == capacity)，印出「紀錄已滿！」。
//   - `void show()`: 依序印出目前儲存的所有歷史紀錄。

// TODO 1: 請在此處「從頭到尾」自己寫出 `RecentHistory` 模板類別！
// 提示：記得在 class 上方寫 `template <typename T>`
template<typename T>
class RecentHistory {
    private:
        T* arr;
        int capacity;
        int count;
    public:
        RecentHistory(int cap){
            capacity = cap;
            count = 0;
            arr = new T [capacity];
        }

        ~RecentHistory(){
            delete [] arr;
            arr = nullptr;
        }

        void add (T item){
            if(isFull()){
                std::cout << "record is full" << std:: endl;
            }else {
                // 關鍵修正 1：資料要放在 count (目前人數) 指向的格子，而不是 capacity！
                // 且應該是 count 遞增，而不是把最大容量 capacity 遞增。
                arr[count] = item;
                count++;
            }
        }

        void show(){
            if(isEmpty()){
                // 關鍵修正 2：補上結尾的分號 `;`
                std::cout << "Currently no any browsing history" << std::endl;
            }else{
                // 關鍵修正 3：必須使用 `for` 迴圈來遍歷從 0 到 count-1 的所有歷史紀錄！
                for (int i = 0; i < count; i++) {
                    std::cout << "- " << arr[i] << std::endl;
                }
            }
        }

        bool isFull(){
            return count == capacity;
        }

        bool isEmpty(){
            return count == 0;
        }
}; // 關鍵修正 4：類別定義結束的大括號後面，必須加上分號 `;`



int main() {
    std::cout << "=== 模擬網站使用者瀏覽行為 ===" << std::endl;

    // TODO 2: 宣告一個「記錄網頁網址 (std::string)」的歷史紀錄器，容量為 3，命名為 pageHistory。
    RecentHistory<std::string> pageHistory(3);


    // TODO 3: 模擬使用者點擊了三個網頁，呼叫 add 將網址加入：
    // 說明：呼叫 add 時，直接在括號內傳入要加入的網址字串！
    pageHistory.add("https://shop.com/home");
    pageHistory.add("https://shop.com/products");
    pageHistory.add("https://shop.com/cart");


    std::cout << "--- 使用者目前的網頁瀏覽歷史紀錄 ---" << std::endl;
    // TODO 4: 呼叫 show() 印出網頁紀錄
    pageHistory.show();



    std::cout << "\n----------------------------------------" << std::endl;

    // TODO 5: 宣告一個「記錄商品 ID (int)」的歷史紀錄器，容量為 5，命名為 productHistory。
    RecentHistory<int> productHistory(5);

    // TODO 6: 模擬使用者瀏覽了商品，加入以下商品 ID：101, 102, 103, 104
    // 說明：呼叫 add 時，直接傳入商品 ID 數字！
    productHistory.add(101);
    productHistory.add(102);
    productHistory.add(103);
    productHistory.add(104);


    std::cout << "--- 使用者最近瀏覽的商品編號 ---" << std::endl;
    // TODO 7: 呼叫 show() 印出商品 ID 紀錄
    productHistory.show();


    return 0;
}
