#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main()
{
    FILE *fp;
    char *json_string;
    long file_size;

    fp = fopen("../99_archivos/actors.json", "rb");
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);
    json_string = (char*) malloc(file_size + 1);
    fread(json_string, sizeof(char), file_size, fp);
    fclose(fp);

    cJSON *root = cJSON_Parse(json_string);
    cJSON *actors = cJSON_GetObjectItem(root, "Actors");
    int actors_count = cJSON_GetArraySize(actors);
    for (int i = 0; i < actors_count; i++)
    {
        cJSON *actor = cJSON_GetArrayItem(actors, i);
        cJSON *name = cJSON_GetObjectItem(actor, "name");
        cJSON *age = cJSON_GetObjectItem(actor, "age");
        printf("Name: %s\nAge: %d\n", name->valuestring, age->valueint);
    }
    cJSON_Delete(root);
    free(json_string);
    return 0;
}
