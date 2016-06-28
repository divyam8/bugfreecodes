
/* Finding path in maze
 * Maze is represented as mXn matrix where cells open for passing through are represented as '.'
 * Closed cells are represented as 'X'.
 * At each point we can go either left, right, top, down.
 * Given starting and ending position, we need to find path from start to end in the maze.
 */

#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;

#define MAX 20

class mazeSolver {
    private:
        int m, n;
        char (*maze)[MAX];
        bool visited[MAX][MAX];
        pair<int, int> parent[MAX][MAX];
        int numSolutions;

        void printPath(pair<int, int> pos)
        {
            int cr = pos.first;
            int cc = pos.second;
            if (parent[cr][cc] == make_pair(-1, -1)) {
                printf("(%d, %d) ", cr, cc);
                return;
            }
            printPath(parent[cr][cc]);
            printf("(%d, %d) ", cr, cc);
        }

        bool solveMaze(int cr, int cc, int fr, int fc, bool needAllPaths)
        {
            if (cr == fr && cc == fc) {
                numSolutions++;
                if (needAllPaths) {
                    printf("\nSolution %d : ", numSolutions);
                }
                printPath(make_pair(fr, fc));
                printf("\n");
                return needAllPaths ? false : true;
            }
            for (int i = 0; i < 4; ++i) {
                const int dr[] = {0, 0, 1, -1};
                const int dc[] = {1,-1, 0, 0};

                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (visited[nr][nc])
                    continue;
                if (maze[nr][nc] == 'X')
                    continue;

                visited[nr][nc] = true;
                parent[nr][nc] = make_pair(cr, cc);
                if (solveMaze(nr, nc, fr, fc, needAllPaths)) {
                    return true;
                }
                visited[nr][nc] = false;
            }
            return false;
        }

    public:
        mazeSolver(char _maze[][MAX], int _m, int _n) : maze(_maze), m(_m), n(_n) {}

        void findPaths(int srcR, int srcC, int destR, int destC, bool needAllPaths=false)
        {
            memset(visited, false, sizeof(visited));
            numSolutions = 0;

            visited[srcR][srcC] = true;
            parent[srcR][srcC] = make_pair(-1, -1);
            parent[destR][destC] = make_pair(-1, -1);

            if (!solveMaze(srcR, srcC, destR, destC, needAllPaths) && numSolutions == 0) {
                printf("No path from (%d-%d) to (%d-%d)\n", srcR, srcC, destR, destC);
            }
        }
};

int main(void)
{
    int t, test, m, n;
    int i;
    int srcR, srcC, destR, destC;
    char maze[MAX][MAX];

    // Sample Input

    /* 
     1      // Number of test cases
     5 5    // Maze dimension
     X.XXX
     X..XX
     XX..X
     X.X.X
     XXX.X
     0 1 4 3 // Starting position is (0, 1) and ending position is (4, 3)
    */

    // freopen("mazeClass.txt", "r", stdin);
    scanf("%d", &test);

    for (t = 0; t < test; ++t) {
        scanf("%d%d", &m, &n);
        for (i = 0; i < m; ++i) {
            scanf("%s", maze[i]);
        }
        scanf("%d%d%d%d", &srcR, &srcC, &destR, &destC);
        mazeSolver ms(maze, m, n);

        printf("TestCase %d : ", t);
        ms.findPaths(srcR, srcC, destR, destC, true);
    }
}
