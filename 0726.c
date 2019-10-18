typedef struct Atom {
    char name[2];
    int num;
} Atom;

typedef struct Table {
    Atom atoms[200];
    int num;
} Table;

void UpdateTable(Table* table, char ch1, char ch2, int num) {
    if (table == NULL) {
        return;
    }
    for (int i = 0; i < table->num; i++) {
        if (table->atoms[i].name[0] == ch1 && table->atoms[i].name[1] == ch2) {
            table->atoms[i].num += num;
            return;
        }
    }
    table->atoms[table->num].name[0] = ch1;
    table->atoms[table->num].name[1] = ch2;
    table->atoms[table->num].num = num;
    table->num++;
    return;
}

void PrintTable(Table* table) {
    printf("%d: ", table->num);
    for (int i = 0; i < table->num; i++) {
        printf("%c%c %d|", table->atoms[i].name[0], table->atoms[i].name[1], table->atoms[i].num);
    }
    printf("\n");
    return;
}

int cmp(const void* a, const void* b) {
    Atom* atom_a = (Atom*)a;
    Atom* atom_b = (Atom*)b;
    int diff = (atom_a->name[0] == atom_b->name[0]) ? (atom_a->name[1] - atom_b->name[1]) : (atom_a->name[0] - atom_b->name[0]);
    return diff;
}
    
char* Table2Str(Table* table) {
    qsort(table->atoms, table->num, sizeof(Atom), cmp);
    PrintTable(table);
    char* str = (char*)malloc(1000);
    memset(str, 0, 1000);
    int len = 0;
    for (int i = 0; i < table->num; i++) {
        str[len++] = table->atoms[i].name[0];
        if (table->atoms[i].name[1] != 0) {
            str[len++] = table->atoms[i].name[1];
        }
        if (table->atoms[i].num > 1) {
            sprintf(str+len, "%d", table->atoms[i].num);
        }
        len = strlen(str);
    }
    //printf("%s\n", str);
    return str;
}

char * countOfAtoms(char * formula){
    Table table;
    table.num = 0;
    
    int len = strlen(formula);
    int multi[500] = {0};
    int pos = 0;
    
    multi[0] = 1;
    pos++;
    
    char ch1 = 0;
    char ch2 = 0;
    int num = 1;
    int num_flag = 0;
    
    
    for (int i = len - 1; i >= 0; i--) {
        char ch = formula[i];
        
        if (ch >= '0' && ch <= '9') {
            num_flag = 1;
            continue;
        }
        
        if (num_flag == 1) {
            sscanf(formula+i+1, "%d", &num);
            num_flag = 0;
        }
        
        if (ch == ')') {
            multi[pos] = multi[pos-1] * num;
            pos++;
            num = 1;
        } else if (ch == '(') {
            pos--;
        } else if (ch >= 'a' && ch <= 'z') {
            ch2 = ch;
        } else {
            ch1 = ch;
            num *= multi[pos-1];
            UpdateTable(&table, ch1, ch2, num);
            ch1 = 0;
            ch2 = 0;
            num = 1;
        }
    }
    //PrintTable(&table);
    return Table2Str(&table);
}
