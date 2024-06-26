#include <stdio.h>
#include <stdbool.h>
#include "Master.h"
#include "Slave.h"
#include "Movie.h"
#include "Actor.h"
#include "Input.h"
#include "Output.h"

#define Movie_IND "movie.ind"
#define IND_SIZE sizeof(struct Ind)

int main()
{
    struct Movie movie;
    struct Actor actor;
    while (true)
    {
        int option;
        int id;
        char error[20];
        printf("\n1 Add a movie\n2 Get movie\n3 Edit movie\n4 Delete movie\n5 Add an actor\n6 Get actor\n7 Edit actor\n8 Delete actor\n9 Show all movies\n10 Show all actors\n0 Exit\nEnter a command:\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                inputMovie(&movie);
                insertMovie(movie);
                break;
            case 2:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error) != 0) outputMovie(movie);
                else printf("Oops, there was an error: %s\n", error);
                break;
            case 3:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                getMovie(&movie, id, error);
                inputMovie(&movie);
                if(updateMovie(movie, error, id) == 0) printf("%s", error);
                else printf("Edited successfully\n");
                break;
            case 4:
                printf("Enter ID: \n");
                scanf("%d", &id);
                if(deleteMovie(id, error) != 0) printf("Deleted successfully\n");
                else printf("Oops, there was an error: %s\n", error);
                break;
            case 5:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error) != 0){
                    inputActor(&actor);
                    actor.movieId = movie.id;
                    insertActor(movie, actor, error);
                    printf("Actor was added successfully\n");
                }
                else printf("Oops, there was an error: %s\n", error);
                break;
            case 6:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error)){
                    printf("Enter actor's ID: \n");
                    scanf("%d", &id);
                    if(checkIfRecordExists(movie, id, error)){
                        getActor(movie, &actor, id, error);
                        outputActor(movie,actor);
                    }
                    else{
                        printf("Oops, there was an error: %s\n", error);
                    }
                }
                else{
                    printf("Oops, there was an error: %s\n", error);
                }
                break;
            case 7:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error)){
                    printf("Enter actor's ID: \n");
                    scanf("%d", &id);
                    if(checkIfRecordExists(movie, id, error)){
                        getActor(movie, &actor, id, error);
                        inputActor(&actor);
                        updateActor(actor);
                        printf("Edited successfully \n ");
                    }
                    else{
                        printf("Oops, there was an error: %s\n", error);
                    }
                }
                else{
                    printf("Oops, there was an error: %s \n", error);
                }
                break;
            case 8:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error)){
                    printf("Enter actor's ID: \n");
                    scanf("%d", &id);
                    if(checkIfRecordExists(movie, id, error)){
                        getActor(movie, &actor, id, error);
                        deleteActor(movie, actor, error);
                        printf("Deleted successfully \n");
                    }
                    else{
                        printf("Oops, there was an error: %s \n ", error);
                    }
                }
                else{
                    printf("Oops, there was an error: %s \n ", error);
                }
                break;
            case 9:
                showMoviesList(error);
                break;
            case 10:
                printf("Enter movie ID: \n");
                scanf("%d", &id);
                if(getMovie(&movie, id, error)){
                    if(movie.actorCount != 0){
                        showListOfActors(movie);
                    }
                    else{
                        printf("This movie has no actors\n");
                    }
                }
                else{
                    printf("Oops, there was an error: %s \n ", error);
                }
                break;
            case 0:
                return 0;
            default:
                printf("There is no such command \n");
        }
        printf("\n");
    }
}