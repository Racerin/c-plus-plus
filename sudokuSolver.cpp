#include <iostream>
#include <fstream>
#include <string>

std::string meWrong = "Something is wrong with my code.";

template <typename idkType>
void print(idkType val){
    //std::printf()
    std::cout << val << std::endl;
}
/*template <typename idkType>
void print(idkType *val, std::string sep) {
    try{
        for(int i=1; i>0; i++){
            std::cout << val[i] << sep << std::endl;
        }
    }
}
template <typename idkType>
void print(idkType *val){print(idkType *val, ' ');}*/

std::string read(){
    std::string ans;
    //std::cin >> ans;
    std::getline(std::cin, ans);
    return ans;
};
std::string userInput(std::string prompt){
    std::cout << prompt << '\n';
    return read();
};
bool stringInString(std::string patt, std::string strung){
    int loc = strung.find(patt);
    return loc!=std::string::npos;
};
bool yesNo(std::string prompt){
    bool ans;
    std::string strAns;
    //prompt update and self
    prompt += " [Y/N]";
    strAns = userInput(prompt);
    //positive
    if(stringInString("y",strAns)){return true;};
    if(stringInString("Y",strAns)){return true;};
    if(strAns.empty()){return true;};
    //negative
    return false;
};
int string2Num(std::string ans){
    int num = std::stoi(ans);
    //int num = atoi(ans.c_str());
    return num;
};
int char2Int(char c){
    int ans = c - '0';
    if(ans<0 or ans>9){throw std::out_of_range("Something is wrong with the int in 'char2Int'.");}
    return ans;
    }

int cell2Block(int row, int col){
    int blockRow, blockCol, blockIndex;
    blockRow = row / 3;
    blockCol = col / 3;
    blockIndex = blockRow*3 + blockCol;
    return blockIndex;
};
int cell2Block(int ind){
    int row = ind / 9;
    int col = ind % 9;
    return cell2Block(row, col);
}
int rc2i(int row, int col){
    return row*9 + col;
}


class NumberCell{
    public:
        int row;
        int col;
        int block;
        
        //int options[];
        int answer = 0;

    NumberCell(){};
    NumberCell(int r, int c, int v){
        //user level inputs
        row = r--; col = c--; answer = v;
        int ind = row*9 + col;
        block = cell2Block(ind);
    }
    NumberCell(int r, int c){NumberCell(r,c,0);}

    std::string printCell(){
        std::string ans = "Row: " + std::to_string(row);
        ans.append(" Column: " + std::to_string(col) );
        ans.append(" Block: " + std::to_string(block) );
        ans.append(" Answer/Value: " + std::to_string(answer) );
        print(ans);
        return ans;
    }

    void setPosition(int r, int c){
        row = r; col = c; block = cell2Block(r,c);
    }
};


class Table{
    private:
        NumberCell cell[9][9];

    public:
        Table(){
            print("Tada.");
        };

        void printTable(){
            int index;
            int num;
            std::string line;

            print("Here is the table");
            for(int i=0; i<9; i++){
                line = "";
                for(int j=0; j<9; j++){
                    index = i*9 + j;
                    //num = cell[index].answer;
                    num = cell[i][j].answer;

                    line += " ";
                    line += std::to_string(num);
                };
                print(line);
            };
        }

        void welcome(){
            //welcome
            std::string ans = "Welcome to sudoku solver.\n";
            //what it's for
            ans += "You could use this app to determine the solution of a sudoku puzzle.\n";
            //how to use
            ans += "To use this application, follow the format of the answers.\n";

            print(ans);
        };

        bool defineCell(int row, int col, int value){
            //convert user value to index values
            row--; col--;
            //get absolute position index
            int index = row*9 + col;
            int block = cell2Block(index);
            //assign to numbercell of index the value;
            //cell[index].row=row; cell[index].col=col; cell[index].block=block; cell[index].answer=value;
            cell[row][col].row=row; 
            cell[row][col].col=col; 
            cell[row][col].block=block; 
            cell[row][col].answer=value;
            return true;
        };

        void preset(){
            //set some default values for the table

            int row,col,val;
            //read text file
            std::string toRead;
            std::fstream file("Number Cell Values.txt");
            //for each line
            while(std::getline(file, toRead)){
                try{
                //get row, col, val
                row=char2Int(toRead[0]);
                col=char2Int(toRead[2]);
                val=char2Int(toRead[4]);
                //assign to NumberCell index the values of row, col, val, etc.
                defineCell(row, col, val);
                }
                catch(std::out_of_range const &e){print("Somewhere in reading the file is a failure.");}
            }
            //printTable();
        }

        bool promptCellValues(){
            std::string ans;
            int row, col, val, num;

            //get coordinate values from user
            for(int i=0; i<3; i++){
                switch(i){
                    //input options
                    case 0:
                        ans = userInput("What is the row position (Number from 1 to 9)? [just press ENTER to cancel]");
                        break;
                    case 1:
                        ans = userInput("What is the column position (Number from 1 to 9)? [just press ENTER to cancel]");
                        break;
                    case 2:
                        ans = userInput("What is the number value at that position (Number from 1 to 9)? [just press ENTER to cancel]");
                        break;
                    default:
                        print(meWrong);
                        break;
                };
                //dealing with errors in number or authenitcating it
                try
	            {
                    //check if empty (cancel) or populated(continue)
                    if(ans.empty()){print("Ok, cancelling number."); return false;}
                    //check if in range
                    num = string2Num(ans);
                    if(num>9 || num==0){throw std::out_of_range("The value is too high, too low or invalid.");};
                    switch(i){
                        case 0: row = num; break;
                        case 1: col = num; break;
                        case 2: val = num; break;
                        default: print(meWrong); break;
                    };
	            }
	            catch (std::invalid_argument const &e)
	            {
	            	print("Thats an invalid number/text. Please try again.");
                    i--;
	            }
	            catch (std::out_of_range const &e)
	            {
	            	std::cout << "Integer overflow: std::out_of_range throw std::out_of_range("")n" << '\n';
	            }
            };
            //NOW, define a cell
            defineCell(row, col, val);
            return true;
        };
        void input(){
            //introduction
            print("Are you ready?. Let's go.");
            //loop asking for results
            bool goOn = true;
            while(goOn){
                //prompt user for cell location and value
                print("Insert cell values.");
                goOn = promptCellValues();
                //if true, go again, else: question to continue.
                if(!goOn){goOn = yesNo("Do you want to go again?");};
            };
            //if empty, escape loop
        }

        bool allCheck(bool bools[], int size){
            bool ans = true;
            for(int i=0; i<size; i++){ans = ans && bools[i];}
            return ans;
        }
        int * blockArrayAnswers(int block){
            int ans[9];
            int counter=0;
            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
                    if(cell[i][j].block == block){
                        ans[counter] = cell[i][j].answer;
                        counter++;
                    }
                }
            }
            return ans;
        }
        bool attempt(){
            int count=0, currentAnswer=0, answered=0;
            int blocks[9];
            bool checks[3];
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    //per cell

                    if(cell[i][j].answer != 0){
                        answered++;
                        //cell[i][j].printCell();
                        //abort if cell populated
                        continue;
                        }
                    //reset
                    count = 0;

                    //for each number, check.   if all check for a number, add to count
                    for(int n=1; n<10; n++){
                        //per possible answer in cell 

                        //reset
                        for(int k=0; k<3; k++){checks[k]=true;}
                        //checks = {true, true, true};

                        //check rows
                        for(int r=0; r<9; r++){
                            if(n==cell[r][j].answer){checks[0]=false;}
                        }
                        //check columns
                        for(int c=0; c<9; c++){
                            if(n==cell[i][c].answer){checks[1]=false;}
                        }
                        //check block
                        /*for(int r=0; r<9; r++){
                            for(int c=0; c<9; c++){
                                //if the block number is the same and if find a same number in the block, then cancel
                                if(n==cell[i][j].answer && cell[i][j].block==cell[r][c].block) {checks[2]=false;}
                            }
                        }*/
                        blocks = blockArrayAnswers(n);
                        //if all check, add to count, set current answer
                        if(allCheck(checks,3));{
                            count++;
                            currentAnswer = n;
                        }
                    }
                    //if count == 1, the number is the currentAnswer
                    if(count==1){
                        cell[i][j].answer=currentAnswer;
                        print("We got the answer: " + cell[i][j].printCell());
                        }
                }

            }
            //end search if all cells are populated
            print("This is answer: "+std::to_string(answered));
            if(answered==81){return true;}
            return false;
        };

        void solveTable(){
            bool success = false;
            std::string emotion;

            print("Ok, let's solve this puzzle.");
            printTable();

            for(int i=0; i<81; i++){
                success = attempt();
                //print("Juan guatamella. " + std::to_string(i) + " " + std::to_string(success) );
                if(success){
                    emotion = "WE SOLVED IT AFTER " + std::to_string(i) + " ATTEMPTS.";
                    printTable();
                    print(emotion);
                    break;
                    }
            }
        };

        void play(){
            //introduction
            welcome();
            //ask for table values
            //input();
            //solve table
            solveTable();
            //print table
            printTable();
            //return
        };
};


int main(){
    Table table;
    table.preset();
    table.play();
    return 0;
};