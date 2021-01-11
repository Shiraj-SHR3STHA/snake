#include<stdio.h>

int new_High_Score () 
{
     FILE *high_score;
     FILE *current_score;
     int  i = 0;
     int  score;
     int  new_score;
     char name[30][30];
     char line[256];

// OPENS THE FILE CONTAINING THE USERS CURRENT SCORE FOR CONSECUTIVE WINS
     current_score = fopen("current_score.txt", "r");
     if (current_score == NULL) 
		{
         printf("ERROR! File could not be opened.\n");
         }
// OBTAINS CURRENT SCORE
     fscanf (current_score, "%d", &new_score);
     fclose(current_score);
// OPENS FILE CONTAINING HIGH SCORES
     high_score = fopen ("scores.txt", "r");
     if (high_score == NULL) {
               puts ("ERROR! Unable to open file.\n");
               fclose(high_score);
        }
// READS "NAME" THEN "SCORE" ON EVERY LINE
     while (fscanf(high_score, "%s %d", name[i], &score) == 2) {
           if (new_score >= score) {
               score = new_score;
               new_score = -1;
               }
               printf("%s\t\t%d\n", name[i], score);
               i++;
           }

// CLOSES FILE
     fclose (high_score);
     return 0;

}
