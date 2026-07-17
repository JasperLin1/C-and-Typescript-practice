#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm> // 核心：使用 std::sort 必須引入此標頭檔

struct Student {
    std::string id;   // 學號 (唯一，例如 "S001")
    std::string name; // 姓名
    int score;        // 分數
};

// ========================================================
// 🏆 終極實作專案：學生成績管理系統 (資料庫持久化版)
// ========================================================
// 恭喜你來到了最後一關！這個專案是整個一個月計畫的總結。
// 你將會整合：
// 1. 結構體 (Struct) ➡️ 封裝學生資料。
// 2. STL Vector ➡️ 儲存學生清單、進行排序。
// 3. STL Map ➡️ $O(1)$ 時間快速檢查學號是否存在、定位學生位置。
// 4. File I/O ➡️ 檔案讀寫，實現關閉程式後資料不遺失的「資料庫」功能！
// 5. STL Algorithms (std::sort) ➡️ 對學生成績進行高效率排序。

class GradeManager {
private:
    std::vector<Student> students;                  // 儲存所有學生資料的動態陣列
    std::unordered_map<std::string, int> idToIndex; // 快速查詢學號 (ID) 對應到 vector 中的哪一個索引 (Index)

    // 輔助函式：當 vector 的順序改變或有刪除時，重新整理 Map 中的索引對照表
    void rebuildMap() {
        idToIndex.clear();
        for (int i = 0; i < students.size(); i++) {
            idToIndex[students[i].id] = i;
        }
    }

public:
    // TODO 1: 從檔案讀取資料 (資料庫初始化)
    void loadFromFile(std::string filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            return; // 檔案不存在就直接返回，不報錯
        }

        students.clear();
        idToIndex.clear();

        // 關鍵修正 1：tempId 應該是 string，tempScore 應該是 int，且宣告為函式內部的區域變數！
        std::string tempId;
        std::string tempName;
        int tempScore;

        while(inFile >> tempId >> tempName >> tempScore){
            Student s;
            s.id = tempId;
            s.name = tempName;
            s.score = tempScore;
            students.push_back(s);
        }
        
        rebuildMap();
        inFile.close(); // 讀完記得關閉檔案！
    }

    // TODO 2: 將目前的學生資料存入檔案 (資料庫備份)
    void saveToFile(std::string filename) {
        std::ofstream outFile(filename);
        if(outFile.is_open()){
            for(Student s : students){
                outFile << s.id << " " << s.name << " " << s.score << std::endl;
            }
            outFile.close(); // 關鍵修正 2：close() 必須放在 for 迴圈「外面」！否則印完第一筆檔案就關閉了，後面的人都印不進去。
        }
    }

    // TODO 3: 新增學生資料 (包含重複學號檢查)
    bool addStudent(std::string id, std::string name, int score) {
        if (idToIndex.find(id) != idToIndex.end()) {
            std::cout << "學號已存在！新增失敗。" << std::endl;
            return false;
        } else {
            // 關鍵修正 3：這裡要把傳進來的參數 id, name, score 包裝進 s，而不是之前的 temp 暫存變數！
            Student s;
            s.id = id;
            s.name = name;
            s.score = score;
            students.push_back(s);

            // 解答你的疑問：為什麼是 students.size() - 1？
            // 因為剛剛 push_back 後，新加入的學生就在 vector 的最後一格。
            // 陣列的索引是從 0 開始，所以最後一格的編號就是「長度減 1」！
            // 這裡把學號與它在陣列中的位置 (最後一格的索引) 記錄到 Map 中，供日後快速查表。
            idToIndex[id] = students.size() - 1; 
            std::cout << "新增學生成功！" << std::endl;
            return true; 
        }
    }

    // TODO 4: 修改學生成績
    bool updateScore(std::string id, int newScore) {
        // 關鍵修正 4：判斷是否「找不到」！
        // 如果 find 回傳等於 end()，代表「找不到」該學號。
        if (idToIndex.find(id) == idToIndex.end()) { 
            std::cout << "找不到該學員！" << std::endl;
            return false;
        } else {
            // 解答你的疑問與修正：如何找到該學生在 vector 中的索引？
            // 只要把學號當成 key，去查 map 即可：`idToIndex[id]` 就會直接回傳那個索引整數！
            int index = idToIndex[id]; 
            
            // 拿著這個索引直接修改 vector 中對應格子裡的分數
            students[index].score = newScore;
            return true; 
        }
    }

    // TODO 5: 刪除學生資料
    // 步驟提示：
    // 1. 檢查學號是否存在。若不存在，return false。
    // 2. 若存在，獲取該學生在 vector 中的索引位置。
    // 3. 在 vector 中刪除該元素：`students.erase(students.begin() + index);`。
    // 4. 由於陣列順序變了，呼叫 `rebuildMap();` 重新整理對照表。
    // 5. return true。
    bool deleteStudent(std::string id) {
        // 關鍵修正 1：檢查學號是否「不存在」（find 到最後 end() 才是找不到）
        if (idToIndex.find(id) == idToIndex.end()) {
            std::cout << "此學生不存在！" << std::endl;
            return false;
        }
        
        // 取得該學生在 vector 的位置
        int index = idToIndex[id];
        
        // 刪除 vector 中的那一格
        students.erase(students.begin() + index);
        
        // 關鍵修正 2：刪除後陣列順序變了，必須重整對照表
        rebuildMap();
        return true;
    }

    // TODO 6: 依成績從高到低進行排序 (使用 std::sort)
    void sortByScore() {
        // 關鍵修正 3：std::sort 接收 lambda 作為第三個參數來進行大到小 (降冪) 排序
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.score > b.score; 
        });
        
        // 排序後順序變了，對照表重新整理
        rebuildMap();
    }

    // 印出所有學生 (已幫你寫好)
    void printAll() {
        if (students.empty()) {
            std::cout << "目前無任何學生資料！" << std::endl;
            return;
        }
        std::cout << "\n--- 學生資料清單 ---" << std::endl;
        std::cout << "學號\t姓名\t分數" << std::endl;
        for (const auto& s : students) {
            std::cout << s.id << "\t" << s.name << "\t" << s.score << std::endl;
        }
    }
};

int main() {
    GradeManager manager;
    std::string dbFile = "students_db.txt";

    // 啟動時自動載入上次儲存的資料
    manager.loadFromFile(dbFile);

    int choice = 0;
    while (choice != 6) {
        std::cout << "\n==============================" << std::endl;
        std::cout << " 🎓 學生成績管理系統 (資料庫版)" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "1. 新增學生資料" << std::endl;
        std::cout << "2. 修改學生成績" << std::endl;
        std::cout << "3. 刪除學生資料" << std::endl;
        std::cout << "4. 顯示所有學生" << std::endl;
        std::cout << "5. 依成績從高到低排序" << std::endl;
        std::cout << "6. 儲存並離開" << std::endl;
        std::cout << "請輸入選項 (1-6): ";
        std::cin >> choice;

        std::string id, name;
        int score;

        switch (choice) {
            case 1:
                std::cout << "輸入學號: "; std::cin >> id;
                std::cout << "輸入姓名: "; std::cin >> name;
                std::cout << "輸入分數: "; std::cin >> score;
                manager.addStudent(id, name, score);
                break;
            case 2:
                std::cout << "輸入要修改的學生學號: "; std::cin >> id;
                std::cout << "輸入新分數: "; std::cin >> score;
                if (manager.updateScore(id, score)) {
                    std::cout << "修改成功！" << std::endl;
                } else {
                    std::cout << "找不到該學號！" << std::endl;
                }
                break;
            case 3:
                std::cout << "輸入要刪除的學生學號: "; std::cin >> id;
                if (manager.deleteStudent(id)) {
                    std::cout << "刪除成功！" << std::endl;
                } else {
                    std::cout << "找不到該學號！" << std::endl;
                }
                break;
            case 4:
                manager.printAll();
                break;
            case 5:
                manager.sortByScore();
                std::cout << "排序完成！請選擇 4 顯示結果。" << std::endl;
                break;
            case 6:
                manager.saveToFile(dbFile);
                std::cout << "資料已儲存！系統安全退出，祝您學習愉快！" << std::endl;
                break;
            default:
                std::cout << "無效的選擇，請重新輸入！" << std::endl;
                break;
        }
    }

    return 0;
}
