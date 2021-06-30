#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <limits.h>

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <cassert>


struct Point {
    Point() : Point(0, 0) {}
    Point(int x, int y) : x(x), y(y) {}
    int x, y;
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
                if(board[i][j]==BLACK)black++;
                else if(board[i][j]==WHITE)white++;
            }
        }
        cur_player = player;
        disc_count[EMPTY] = 64-black-white;
        disc_count[BLACK] = black;
        disc_count[WHITE] = white;
        done = false;
        winner = -1;
        next_valid_spots = get_valid_spots();
    }
    Board(Board const&cur_board) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = cur_board.board[i][j];
            }
        }
        disc_count[EMPTY] = cur_board.disc_count[EMPTY];
        disc_count[BLACK] = cur_board.disc_count[BLACK];
        disc_count[WHITE] = cur_board.disc_count[WHITE];
        cur_player = cur_board.cur_player;
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
    if (cur.winner == player)
        return INT_MAX;
    int state_value[8][8]={
    10000,  -1000, 100, 60, 60, 100, -1000,  10000,
    -1000, -1200, 30, 10, 10, 30, -1200, -1000,
     100,   300, 50, 30, 30, 50,  30 ,   100,
     60,   100, 30, 10, 10, 30,  100,   60, 
     60,   100, 30, 10, 10, 30,  100,   60,
     100,   300, 50, 30, 30, 50,  30 ,   100, 
    -1000, -1200, 30, 10, 10, 30, -1000, -1000,
    10000,  -1000, 100, 60, 60, 100,  -1000, 10000,
    };
    int playerh = 0, opponenth = 0;
    for(int i=0;i<8;i++) {
        for(int j = 0;j<8;j++) {
            if(cur.board[i][j] == player) {
                playerh+= state_value[i][j];
            } else if(cur.board[i][j] == 3 - player) {
                opponenth += state_value[i][j];
            }
        }
    }
    return playerh - opponenth;

}
Point p;
static const int DEPTH = 7;

int minimax(Board board,int depth, int alpha,int beta,int maxmizingPlayer) {
    if(depth==0 ||board.done) 
        return get_state_value(board);
    else {
        if(maxmizingPlayer == player) {
            int maxvalue  = INT_MIN;
            for(auto i : board.next_valid_spots) {
                Board new_board = board;
                new_board.put_disc(i);
                int value = minimax(new_board, depth - 1, alpha, beta,3 - maxmizingPlayer );
                if(depth == DEPTH  && value > maxvalue) {
                    p = i;
                }
                maxvalue = max(value,maxvalue);
                alpha = max(maxvalue,alpha);
                if(alpha >= beta) break;
            }
            return maxvalue;
        } else if(maxmizingPlayer == 3 - player) {
            int minvalue  = INT_MAX;
            for(auto i: board.next_valid_spots) {
                Board new_board = board;
                new_board.put_disc(i);
                int value = minimax(new_board, depth - 1,alpha,beta,3 - maxmizingPlayer ); 
                minvalue = min(value,minvalue);
                beta = min(beta,minvalue);
                if(alpha >= beta) break;
            }
            return minvalue;
        }
    }
}

void read_valid_spots(std::ifstream& fin){
    int n_valid_spots;
    fin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++) {
        fin >> x >> y;
        Point z(x,y);
        next_valid_spots.push_back(z);
    }
}
void write_valid_spot(std::ofstream& fout) {
    fout << p.x << " " << p.y << std::endl;
    fout.flush();
}


int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    int alpha = INT_MIN;
    int beta = INT_MAX;
    read_valid_spots(fin);
    Board mainboard(board,player);
    minimax(mainboard,DEPTH,alpha,beta,player);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}




