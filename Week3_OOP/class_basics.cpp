#include <iostream>
#include <string>

// ========================================================
// 知識點: 什麼是類別 (Class) 與物件 (Object)？
// ========================================================
// - 類別 (Class) 是藍圖：定義了資料 (變數) 與行為 (函式)。
// - 物件 (Object) 是實體：用藍圖造出來的實際東西。
//
// 封裝 (Encapsulation)：
// - `private` (私有)：只有類別內部可以存取，外部摸不到。用於保護資料。
// - `public` (公開)：外部可以自由存取的介面。
//
// 建構子 (Constructor) 與 解構子 (Destructor)：
// - 建構子：物件出生時自動執行的函式，用來初始化資料。名字與 Class 相同。
// - 解構子：物件死亡（被銷毀/釋放）時自動執行的清掃函式。名字是 `~Class`。

class Student {
private:
    std::string name; // 姓名 (私有，外部不能直接修改)
    int score;        // 分數 (私有，外部不能直接修改)

public:
    // TODO 1: 實作建構子 (Constructor)
    // 說明：建構子接收外部傳入的 n 與 s，用來初始化內部的私有變數 name 與 score。
    Student(std::string n, int s) {
        name = n;   // 將私有成員變數 name 設定為傳入的 n
        score = s;  // 將私有成員變數 score 設定為傳入的 s
    }

    // TODO 2: 實作解構子 (Destructor)
    ~Student() {
        std::cout << "學生物件 " << name << " 已被銷毀。" << std::endl;
    }

    // TODO 3: 實作 Getter (取得私有資料的公開函式)
    // 說明：Getter 不需要參數，只要把私有變數 return 回去給呼叫者即可。
    std::string getName() {
        return name; 
    }
    
    int getScore() {
        return score; 
    }

    // TODO 4: 實作 Setter (修改私有資料的公開函式，加入安全檢查！)
    void setScore(int newScore) {
        if(newScore <= 100 && newScore >= 0){
            score = newScore;
        }else{
            std::cout << "error: invalid score" << std :: endl;
        }
    }
};

int main() {
    std::cout << "=== 1. 測試 Stack 物件 the 生命週期 ===" << std::endl;
    {
        // 用大括號 `{}` 限制生命範圍
        // TODO 5: 在 Stack 宣告一個名為 s1 的 Student 物件，名字叫 "Jasper"，分數 90 分。
        // 說明：類別也是一種資料型態，寫法就像 `Student s1(參數1, 參數2);`
        Student s1("Jasper", 90);

        // 測試修改分數
        std::cout << "嘗試修改 " << s1.getName() << " 的分數為 98 分..." << std::endl;
        s1.setScore(98);
        std::cout << s1.getName() << " 目前的分數是: " << s1.getScore() << std::endl;

        // 測試輸入錯誤的分數 (安全機制應該會擋下來)
        std::cout << "嘗試修改分數為 150 分 (無效分數)..." << std::endl;
        s1.setScore(150);
        std::cout << s1.getName() << " 的分數依然是: " << s1.getScore() << std::endl;
        
        std::cout << "--- 離開大括號範圍，Stack 物件準備死亡 ---" << std::endl;
    } // 離開大括號後，s1 應該會自動被釋放，並觸發解構子！

    std::cout << "\n=== 2. 測試 Heap 物件的生命週期 ===" << std::endl;
    
    // TODO 6: 在 Heap 動態配置一個 Student 物件，名字叫 "Bob"，分數 80 分。
    // 說明：用 new 呼叫建構子，並用指標 Student* 接收地址
    Student* s2 = new Student("Bob", 80);


    std::cout << "印出 s2 的資訊：" << std::endl;
    // 解除下方註解來測試：
    std::cout << s2->getName() << " 的分數是: " << s2->getScore() << std::endl;

    std::cout << "--- 準備手動釋放 Heap 物件 ---" << std::endl;
    // TODO 7: 用 delete 釋放 s2 指向的物件，觀察解構子是否會在此刻觸發！
    delete s2;
    s2 = nullptr;



    std::cout << "程式結束。" << std::endl;
    return 0;
}
