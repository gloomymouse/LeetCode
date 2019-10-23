bool VisitRooms(int** rooms, int roomsSize, int* roomsColSize, bool* visit, int* visit_num, int cur_room) {
    visit[cur_room] = 1;
    (*visit_num)++;
    if (*visit_num == roomsSize) {
        return true;
    }
    
    for (int i = 0; i < roomsColSize[cur_room]; i++) {
        if (visit[rooms[cur_room][i]] == 1) {
            continue;
        }
        if (VisitRooms(rooms, roomsSize, roomsColSize, visit, visit_num, rooms[cur_room][i]) == true) {
            return true;
        }
    }
    
    return false;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int visit_num = 0;
    int visit[1000];
    memset(visit, 0, sizeof(int)*1000);
    return VisitRooms(rooms, roomsSize, roomsColSize, visit, &visit_num, 0);
}
