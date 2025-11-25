#include <stdio.h>
#include <stdlib.h>
int seed = 42;

void shuffle(int *a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = rand() % size;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

void dfs(char **lab, int x, int y, char wall_c, char road_c)
{
    int dir[4] = {0, 1, 2, 3};
    int can_use[4] = {0, 0, 0, 0};
    shuffle(dir, 4);
    for (int i = 0; i < 4; ++i)
    {
        int r = dir[i];
        if (r == 0 && (lab[x - 1][y] == wall_c || lab[x - 1][y] == road_c))
        {
            continue;
        }
        else if (r == 1 && (lab[x][y + 1] == wall_c || lab[x][y + 1] == road_c))
        {
            continue;
        }
        else if (r == 2 && (lab[x + 1][y] == wall_c || lab[x + 1][y] == road_c))
        {
            continue;
        }
        else if (r == 3 && (lab[x][y - 1] == wall_c || lab[x][y - 1] == road_c))
        {
            continue;
        }
        can_use[r] = 1;
    }

    lab[x][y - 1] = (lab[x][y - 1] != road_c) ? wall_c : road_c;
    lab[x][y + 1] = (lab[x][y + 1] != road_c) ? wall_c : road_c;
    lab[x - 1][y] = (lab[x - 1][y] != road_c) ? wall_c : road_c;
    lab[x + 1][y] = (lab[x + 1][y] != road_c) ? wall_c : road_c;
    for (int i = 0; i < 4; ++i)
    {
        int r = dir[i];
        if (r == 0 && can_use[r])
        {
            lab[x][y] = road_c;
            dfs(lab, x - 1, y, wall_c, road_c);
        }
        else if (r == 1 && can_use[r])
        {
            lab[x][y] = road_c;
            dfs(lab, x, y + 1, wall_c, road_c);
        }
        else if (r == 2 && can_use[r])
        {
            lab[x][y] = road_c;
            dfs(lab, x + 1, y, wall_c, road_c);
        }
        else if (r == 3 && can_use[r])
        {
            lab[x][y] = road_c;
            dfs(lab, x, y - 1, wall_c, road_c);
        }
    }
}

void set_bounds(char **lab, char wall_c, char road_c, int lab_size)
{
    for (int j = 0; j < lab_size; ++j)
    {
        lab[0][j] = wall_c;
    }
    for (int i = 1; i < lab_size - 1; ++i)
    {
        lab[i][0] = wall_c;
        for (int j = 1; j < lab_size - 1; ++j)
        {
            lab[i][j] = (char)(road_c + 1);
        }
        lab[i][lab_size - 1] = wall_c;
    }
    for (int j = 0; j < lab_size; ++j)
    {
        lab[lab_size - 1][j] = wall_c;
    }
}

void print_lab(char **lab, int lab_size)
{
    for (int i = 0; i < lab_size; ++i)
    {
        for (int j = 0; j < lab_size; ++j)
        {
            printf("%c", lab[i][j]);
        }
        printf("\n");
    }
}

void fill_gaps(char **lab, int lab_size, char wall_c, char road_c)
{
    for (int i = 0; i < lab_size; ++i)
    {
        for (int j = 0; j < lab_size; ++j)
        {
            if (lab[i][j] == (char)(road_c + 1))
            {
                lab[i][j] = wall_c;
            }
        }
    }
}

int main()
{
    srand(seed);
    int lab_size = 6;
    int x_start = rand() % (lab_size - 2) + 1;
    int y_start = rand() % (lab_size - 2) + 1;
    char wall_c = '#';
    char road_c = '.';

    char **lab;
    lab = malloc(lab_size * sizeof(char *));
    for (int i = 0; i < lab_size; ++i)
    {
        lab[i] = malloc(lab_size * sizeof(char));
    }
    set_bounds(lab, wall_c, road_c, lab_size);
    dfs(lab, x_start, y_start, wall_c, road_c);
    fill_gaps(lab, lab_size, wall_c, road_c);
    print_lab(lab, lab_size);
    for (int i = 0; i < lab_size; ++i)
    {
        free(lab[i]);
    }
    free(lab);
    return 0;
}
