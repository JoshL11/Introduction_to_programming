#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>

#define INF 0x7FFFFFFF

struct Point {
    Point() : Point(0, 0) {}
    Point(float x, float y) : x(x), y(y) {}
    float x, y;
    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const Point& rhs) const {
        return !operator==(rhs);
    }
    Point operator+(const Point& rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
};

class Board {
public:
    enum SPOT_STATE {
        EMPTY = 0,
        BLACK = 1,
        WHITE = 2
    };
    static const int SIZE = 8;
    const std::array<Point, 8> directions{{
        Point(-1, -1), Point(-1, 0), Point(-1, 1),
        Point(0, -1), /*{0, 0}, */Point(0, 1),
        Point(1, -1), Point(1, 0), Point(1, 1)
    }};
    std::array<std::array<int, SIZE>, SIZE> board;
    std::vector<Point> next_valid_spots;
    std::array<int, 3> disc_count;
    int cur_player;
    bool done;
    int winner;
    int get_next_player(int player) const {
        return 3 - player;
    }
private:
    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    int get_disc(Point p) const {
        return board[p.x][p.y];
    }
    void set_disc(Point p, int disc) {
        board[p.x][p.y] = disc;
    }
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (get_disc(p) != disc)
            return false;
        return true;
    }
    bool is_spot_valid(Point center) const {
        if (get_disc(center) != EMPTY)return false;
        for (Point dir: directions) {
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(cur_player)))continue;
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player))
                    return true;
                p = p + dir;
            }
        }
        return false;
    }
    void flip_discs(Point center) {
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(cur_player)))continue;
            std::vector<Point> discs({p});
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player)) {
                    for (Point s: discs) {
                        set_disc(s, cur_player);
                    }
                    disc_count[cur_player] += discs.size();
                    disc_count[get_next_player(cur_player)] -= discs.size();
                    break;
                }
                discs.push_back(p);
                p = p + dir;
            }
        }
    }
public:
    Board(int new_board[8][8] , int player) {
      int black=0,white=0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = new_board[i][j];
                if(board[i][j]==1)black++;
                else white++;
            }
        }
        cur_player = player;
        disc_count[EMPTY] = 64-black-white;
        disc_count[BLACK] = black;
        disc_count[WHITE] = white;
        next_valid_spots = get_valid_spots();
    }
    Board(Board const&cur_board) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = cur_board.board[i][j];
            }
        }
        cur_player = cur_board.cur_player;
        disc_count[EMPTY] = cur_board.disc_count[EMPTY];
        disc_count[BLACK] = cur_board.disc_count[BLACK];
        disc_count[WHITE] = cur_board.disc_count[WHITE];
        next_valid_spots = cur_board.next_valid_spots;
        done = cur_board.done;
        winner = cur_board.winner;
    }
    std::vector<Point> get_valid_spots() const {
        std::vector<Point> valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != EMPTY)
                    continue;
                if (is_spot_valid(p))
                    valid_spots.push_back(p);
            }
        }
        return valid_spots;
    }
    bool put_disc(Point p) {
        if(!is_spot_valid(p)) {
            winner = get_next_player(cur_player);
            done = true;
            return false;
        }
        set_disc(p, cur_player);
        disc_count[cur_player]++;
        disc_count[EMPTY]--;
        flip_discs(p);
        cur_player = get_next_player(cur_player);
        next_valid_spots = get_valid_spots();
        if (next_valid_spots.size() == 0) {
            cur_player = get_next_player(cur_player);
            next_valid_spots = get_valid_spots();
            if (next_valid_spots.size() == 0) {
                done = true;
                int white_discs = disc_count[WHITE];
                int black_discs = disc_count[BLACK];
                if (white_discs == black_discs) winner = EMPTY;
                else if (black_discs > white_discs) winner = BLACK;
                else winner = WHITE;
            }
        }
        return true;
    }
};



int player;
const int SIZE = 8;
int board[8][8];
std::vector<Point> next_valid_spots;
void read_board(std::ifstream& fin) {
    fin >> player;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
}
int get_state_value(Board cur){
    int state_value[8][8]={
    100,  -15, 10, 6, 6, 10, -15,  100,
    -15, -40, 3, 1, 1, 3, -40, -15,
     10,   3, 5, 3, 3, 5,  3,   10,
     6,   1, 3, 1, 1, 3,  1,   6, 
     6,   1, 3, 1, 1, 3,  1,   6,
     10,   3, 5, 3, 3, 5,  3,   10, 
    -15, -40, 3, 1, 1, 3, -40, -15,
    100,  -15, 10, 6, 6, 10,  -15, 100,
    };
    int white = 0,black = 0;
    for(int i=0;i<8;i++) {
        for(int j = 0;j<8;j++) {
            if(cur.board[i][j] == 1) {
                black += state_value[i][j];
            } else if(cur.board[i][j] == 2) {
                white += state_value[i][j];
            }
        }
    }
    if(cur.cur_player == 1) return black;
    else return white;
}

int minimax(Board board,int depth, int maxmizingPlayer) {
    if(depth == 0) 
        return get_state_value(board);
    else {
            if(maxmizingPlayer == 1){
                Board new_board = board;
                for(int i=0;i<new_board.next_valid_spots.size();i++) {
                    new_board.put_disc(next_valid_spots[i]);
                    int next_player = 2;
                    int maxvalue  = -INFINITY;
                    int value = minimax(new_board, depth - 1,next_player );
                    maxvalue = max(value,maxvalue);
                    return maxvalue;
                }
            } else {
                Board new_board = board;
                for(int i=0;i<new_board.next_valid_spots.size();i++) {
                    new_board.put_disc(next_valid_spots[i]);
                    int next_player = 1;
                    int minvalue  = INFINITY;
                    int value = minimax(new_board, depth - 1,next_player ); 
                    minvalue = min(value,minvalue);
                    return minvalue;
            }
            
            
        }
    }
}

void read_valid_spots(std::ifstream& fin){
    int n_valid_spots;
    fin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++) {
        fin >> x >> y;
        next_valid_spots.push_back({(float)x, (float)y});
    }
}
void write_valid_spot(std::ofstream& fout) {
    int n_valid_spots = next_valid_spots.size();
    int index = -1;
    //int alpha = -INF , beta = INF;
    for(int i=0;i < n_valid_spots;i++){
        Board next(board , player);
        next.put_disc(next_valid_spots[i]);
        int next_player;
        if(player == 1) next_player = 2;
        else next_player = 1;
        int value = minimax(next , 5  , next_player);
    }
    Point p = next_valid_spots[index];
    fout << p.x << " " << p.y << std::endl;
    fout.flush();
}


int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    read_valid_spots(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}




