/* 
Uzdevums Nr. 2:
Taisnstūrveida tabulā ir N rindas un M kolonnas. Katra rūtiņa ir vai nu tukša, vai nokrāsota. 
Katra nokrāsotā rūtiņa pieder kādai figūrai. Ja divām nokrāsotām rūtiņām ir kopīga mala, 
tad tās pieder vienai figūrai. Tukšās rūtiņas figūrām nepieder. Par figūras laukumu sauksim 
figūrai piederošo rūtiņu skaitu. Attēlā dotajā piemērā ir trīs figūras, kuru laukumi ir 3, 19 un 2. 

**Jāuzraksta programmu kura atrod lielākās figūras laukumu (max 9).
***Uzdevumu jāatrisina izmantojot rekursīvo funkciju (max 10).
*/

/*
Avoti: 
    1. https://stackoverflow.com/questions/16446231/how-to-find-largest-figure-in-2d-array ;
    2. https://en.wikipedia.org/wiki/Connected-component_labeling ;
    3. https://stackoverflow.com/questions/53247243/how-should-i-implement-a-flood-fill-function-to-my-c-program
*/

#include <iostream>
#include <vector>
#include <queue>     //Priekš funkcijām: push(), pop(), front(), empty()
#include <algorithm> //Priekš max()

//Virzieni pa asīm, lai pārbaudītu četrus tuvākos kaimiņus (augša, apakša, pa kreisi, pa labi)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

//FlooFill funkcija: https://stackoverflow.com/questions/53247243/how-should-i-implement-a-flood-fill-function-to-my-c-program
int floodfill(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int startX, int startY) {
    int rows = grid.size();     //Kopējais rindu skaits
    int cols = grid[0].size();  //Kopējais kolonnu skaits
    int size = 0;

    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});           //Pievieno sākuma šūnu rindai
    visited[startX][startY] = true;     //Iezīmē atrasto sākuma šūnu

    while (!q.empty()) {                        //!q kamēr rinda nav tukša (empty() )
        std::pair<int, int> cell = q.front();   //Izņem pirmo šūnu no rindas
        q.pop();                                //Izņem šūnu no rindas
        int x = cell.first;                     //Definē rindu indeksu
        int y = cell.second;                    //Definē kolonnu indeksu
        size++;

        //Šeit notiek tuvāko kaimiņu pārbaude (pa labi, pa kreisi, uz augšu uz leju)
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            //Notiek pārbaude vai tuvākais kaimiņš ir atrasts, atrodas laukuma robežās, ir figūras daļa
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({nx, ny});       //Pievieno tuvāko kaimiņu rindai
                visited[nx][ny] = true; //Atzīme, kas apliecina, ka kaimiņš ir atrasts
            }
        }
    }

    return size;
}

int main() {

    //Laukums izveidots no .pptx parauga
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0}
    };

    int rows = grid.size();
    int cols = grid[0].size();

    //Apskata, kuras šūnas, figūras jau ir apmeklētas
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    int maxarea = 0;

    //Tiek validēts grid, jeb režģis
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {        //Ja šūna ir režģī ir 1, tad tiek ierosināta funkcija floodfill
                int area = floodfill(grid, visited, i, j);  //Aprēķināts figūras laukums
                maxarea = std::max(maxarea, area); 
            }
        }
    }

    std::cout << "Lielaakaas figuuras laukums ir: " << maxarea << std::endl;

    return 0;
}