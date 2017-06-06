// https://leetcode.com/problems/length-of-last-word/#/description
int lengthOfLastWord(char* s) 
{
    char* pointer;
    pointer = strtok(s, " ");
    int ret = pointer == NULL ? 0 : strlen( pointer );
    while(pointer != NULL)
    {
        pointer = strtok(NULL, " ");
        ret = pointer == NULL ? ret : strlen( pointer );
    }
    return ret;
}
