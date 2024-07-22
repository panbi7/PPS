class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record; // 기록을 저장할 스택
        
        for (const string& op : operations) {
            if (op == "C") {
                // 이전 점수 무효화
                if (!record.empty()) {
                    record.pop();
                }
            } else if (op == "D") {
                // 이전 점수의 두 배 추가
                if (!record.empty()) {
                    record.push(2 * record.top());
                }
            } else if (op == "+") {
                // 이전 두 점수의 합 추가
                if (record.size() >= 2) {
                    int top = record.top();
                    record.pop();
                    int newTop = top + record.top();
                    record.push(top); // 원래의 top 복원
                    record.push(newTop);
                } else if (record.size() == 1) {
                    record.push(record.top());
                }
            } else {
                // 새로운 점수 추가
                record.push(std::stoi(op));
            }
        }
        
        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }
        
        return sum;
        }
    };