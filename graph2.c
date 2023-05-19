//2020314543 오승준 무방향 그래프 과제
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// vertex edge graph 선언
typedef char element;

typedef struct _Vertex{
    element _data;
    struct _Vertex* nextV; 
    struct _Edge* headE;
    int visited;
}V;

typedef struct _Edge{
    struct _Vertex* curV;
    struct _Edge* nextE;
}E;

typedef struct _Graph{
    struct _Vertex* headV;
}G;
// ADT 선언 
void init_Graph(G* g); //clear
V* init_Vertex(element data); //clear
V* find_vertex(G* g, element data); //clear
void reset_visited(G* g); //clear
void insert_vertex(G* g,element data); // clear
void add_edge(V* v1,V* v2); // clear
void printE(V* curV); // clear
void print(G* g); // clear
int degree_of_vertex(V* v); //clear
void is_connected(G* g); // clear
void is_empty(G* g); // clear
void adjacaent(V* v); // clear
void delete_edge(V* v1,V* v2); // clear
void delete_vertex(G* g,V* v);  // almost clear;;
int path_exist(V* startV,V* endV); // clear
int num_of_vertex(G* g); // clear
int num_of_edge(G* g); // clear
void rename_vertex(V* v,element data);// clear
int path_exist(V* startV,V* endV); // clear
void clear(G* g); //clear
int maxdegreeofG(G* g); // 창작 기능 1 그래프의 최대 차수 구하기 clear
int mindegreeofG(G* g); // 창작 기능 2 그래프의 최소 차수 구하기 clear
int minTomax(G* g); // 창작 기능 3 그래프의 최대 차수와 최소 차수의 차이값 구하기 clear

void screen(){
    printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("=========================USE ADT COMMAND===================================\n");
	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("G :                                        init_Grapg() ===================\n");
	printf("+? :                                   insert_vertex() ===================\n");
	printf("E(,) :                                       add_edge() ===================\n");
	printf("L :                                             print() ===================\n");
	printf("V() :                                  degreeofVertex() ===================\n");
	printf("C :                                      is_connected() ===================\n");
	printf("N :                                          is_empty() ===================\n");
	printf("A() :                                        adjacent() ===================\n");
	printf("-? :                                   delete_vertex() ===================\n");
	printf("P(,) :                                     path_exist() ===================\n");
	printf("X :                                       numofVertex() ===================\n");
	printf("H :                                         numofEdge() ===================\n");
	printf("D(,) :                                    delete_edge() ===================\n");
	printf("R(,) :                                 renameofVertex() ===================\n");
	printf("K :                                             clear() ===================\n");
	printf("M :                                       maxofdegree() ===================\n");
	printf("m :                                       minofdegree() ===================\n");
	printf("T :                                          maxTomin() ===================\n");
	printf("Q:                                                 Quit ===================\n");
	printf("===========================================================================\n\n");
}
//main 
int main(){
    screen();
   
   int bIterFlag = 1;
   char command[10];
   int i = 0;
    G* g =(G*)malloc(sizeof(G));


   while(bIterFlag){
    printf("Please input your COMMAND : ");
    fgets(command,10,stdin);

    if(command[i]=='G'){
        printf("You choose init_Graph! \n");
        init_Graph(g);
    }
    else if(command[i]=='+'){
        printf("You choose insert_vertex! \n");
        insert_vertex(g,command[1]);
    }
    else if(command[i]=='E'){
        printf("You choose add_edge! \n");
        V* v1=find_vertex(g,command[2]);
        V* v2=find_vertex(g,command[4]);
        add_edge(v1,v2);
    }
    else if(command[i]=='L'){
        printf("You choose printGraph!\n");
        print(g);
    }
    else if(command[i]=='V'){
        printf("You choose degreeofVertex!\n");
        V* v=find_vertex(g,command[2]);
        printf("The vertex degree is %d \n",degree_of_vertex(v));
    }
    else if(command[i]=='C'){
        printf("You choose is_connected!\n");
        is_connected(g);
    }
    else if(command[i]=='N'){
        printf("You choose is_empty!\n");
        is_empty(g);
    }
    else if(command[i]=='A'){
        printf("You choose adjacent!\n");
        V* v=find_vertex(g,command[2]);
        adjacaent(v);
    }
    else if(command[i]=='-'){
        printf("You choose deleteVertex\n");
        V* v = find_vertex(g,command[1]);
        delete_vertex(g,v);
    }
    else if(command[i]=='P'){
        printf("You choose pathExist!\n");
        V* startV = find_vertex(g,command[2]);
        V* endV = find_vertex(g,command[4]);
        if( path_exist(startV,endV) == 1 ) printf("TRUE !! \n");
        else printf("FALSE !! \n");
    }
    else if(command[i]=='X'){
        printf("You choose numofVertex!\n");
        printf(" NUMBER OF VERTEX IS %d \n",num_of_vertex(g));
    }
    else if(command[i]=='H'){
        printf("You choose numofEdge!\n");
        printf("NUMBER OF EDGE IS %d \n",num_of_edge(g));
    }
    else if(command[i]=='D'){
        printf("You choose deleteEdge!\n");
        V* v1 = find_vertex(g,command[2]);
        V* v2 = find_vertex(g,command[4]);
        delete_edge(v1,v2);
    }
    else if(command[i]=='R'){
        printf("You choose renameVertex!\n");
        V* v = find_vertex(g,command[2]);
        rename_vertex(v,command[4]);
    }
    else if(command[i]=='K'){
        printf("You choose clearGraph!\n");
        clear(g);
    }
    else if(command[i]=='M'){
        printf("You choose MaxdegreeofGraph!\n");
        printf("MAX DEGREE OF GRAPH IS %d \n",maxdegreeofG(g));
    }
    else if(command[i]=='m'){
        printf("You choose mindegreeofGraph!\n");
        printf("MIN DEGREE OF GRAPH IS %d \n",mindegreeofG(g));
    }
    else if(command[i]=='T'){
        printf("You choose Gap Max & min!\n");
        printf("GAP BETWEEN MAX DEGREE OF GRAPH & MIN DEGREE OF GRAPH IS %d \n",minTomax(g));
    }
    else if(command[i]=='Q'){
        printf("You choose QUIT! \n");
        printf("QUIT !!! \n");
        return 0;
    }
    else{
        printf("COMMAND IS ERROR \n PLEASE COMMAND INPUT AGAIN! \n");
    }
   }

}


// ADT 구현
void init_Graph(G* g){
    g->headV = NULL;
}

V* init_Vertex(element data){
    V* newV = (V*)malloc(sizeof(V));
    newV -> headE =NULL;
    newV -> nextV =NULL;
    newV ->visited =0;
    newV->_data =data;
    return newV;
}
V* find_vertex(G* g,element data){
    V* tmpV = g->headV;
    while(tmpV != NULL){
        if(tmpV->_data == data) return tmpV;
        tmpV = tmpV->nextV;
    }
    return NULL;
}
void reset_visited(G* g){
    V* tmpV = g->headV;
    while( tmpV !=NULL){
        tmpV->visited = 0;
        tmpV= tmpV->nextV;
    }
}
void insert_vertex(G* g,element data){
    V* newV = init_Vertex(data);
    newV->nextV = g->headV;
    g->headV = newV;
}
void add_edge(V* v1,V* v2){ // 강의영상 보고 다시
    // 새로운 간선 동적할당
    E* newE1 = (E*)malloc(sizeof(E));
    E* newE2 = (E*)malloc(sizeof(E));
    
    // 새로운 간선의 도착 지점 설정
    newE1 -> curV = v2;
    newE1 -> nextE = NULL;
    newE2 -> curV = v1;
    newE2 -> nextE = NULL;

    // 첫번째 간선 연결
    newE1 -> nextE = v1->headE;
    v1->headE = newE1;
    
    // 두번째 간선 연결
    newE2 -> nextE = v2->headE;
    v2->headE = newE2;
} 
void printE(V* current){
    E* tmpE = current->headE;

    if(tmpE != NULL){//headE가 존재할때
        printf("(");
        while(tmpE != NULL){
            printf("%c" ,tmpE->curV->_data);
            tmpE = tmpE ->nextE;
            if(tmpE != NULL){ // 다음 간선이 존재하면 
                printf(",");
            }
        }
        printf(")");
    }
}
void print(G* g){
    V* tmpV = g->headV;
    printf("(");
    while(tmpV != NULL){
        printf("%c", tmpV->_data);
        printE(tmpV);
        tmpV = tmpV->nextV;
        if(tmpV != NULL){ // 다음 정점이 존재하면
            printf(",");
        }
    }
    printf(") \n");
}
int degree_of_vertex(V* v){
    E* tmpE = v->headE;
    int cnt=0;
    if(v == NULL) return -1; // 없는 정점일경우
    if(tmpE==NULL) return cnt; // 간선이 하나도 없는 경우
    while(tmpE !=NULL){
        cnt++;
        tmpE = tmpE ->nextE;
    }
    return cnt;
}

void is_connected(G* g){
    V* tmpV = g->headV;
    while( tmpV != NULL){
        if (degree_of_vertex(tmpV) ==0 ){
            printf("FALSE !! \n");
            return;
        }
        tmpV = tmpV->nextV;
    }
    printf("TRUE !! \n");
}

void is_empty(G* g){
    if(g->headV != NULL) printf("FALSE !! \n");
    else printf("TRUE !! \n");
}

void adjacaent(V* v){
    E*  tmpE = v->headE;
    if(degree_of_vertex(v) !=0 ){
        printf("{");
        while(tmpE != NULL ){
            printf("%c",tmpE->curV->_data);
            tmpE = tmpE ->nextE;
            if(tmpE != NULL) printf(",");
        }
        printf("}");
    }
    printf("\n");
}

void delete_edge(V* v1,V* v2){
    E* tmpE = v1->headE;
    E* delE1 ;
    E* delE2 ;
    if(tmpE->curV ==v2){
        v1->headE = v1->headE->nextE;
        free(tmpE);
    }
    else{
        while(tmpE->nextE->curV != v2 ){
            tmpE = tmpE ->nextE;
        }
        delE1 = tmpE->nextE;
        tmpE->nextE = tmpE->nextE->nextE;
        free(delE1);
    }

    E* tmpE2 = v2->headE;
    if(tmpE2->curV == v1){
        v2->headE =v2->headE ->nextE;
    }
    else{
        while(tmpE2->nextE->curV != v1 ){
            tmpE2 = tmpE2 ->nextE;
        }
        delE2 = tmpE2->nextE;
        tmpE2->nextE = tmpE2->nextE->nextE;
        free(delE2);
    }
}// 잘됨
void delete_vertex(G* g,V* v){
    V* tmpV = g->headV;
    if(tmpV ==NULL) {
        printf("NO DATA ! \n");
        return;
    }
    E* tmpE = v->headE;
    V* del;

    // v와 연결된 간선들부터 delete
    while(tmpE !=NULL){
        del = tmpE->curV;
        delete_edge(v,del);
        tmpE = v->headE;
    }

    // 정점의 연결리스트에서 정점 삭제
    if (v == g->headV) g->headV = v->nextV;
    else{
        while(tmpV-> nextV != v){
            tmpV = tmpV ->nextV;
        }
        del = tmpV->nextV;
        tmpV->nextV = tmpV->nextV ->nextV;
        free(del);
    }   
}// 잘됨
int num_of_vertex(G* g){
    int cnt = 0;
    V* tmpV = g->headV;
    if(tmpV ==NULL) return cnt; // 정점이 하나도 없을떄
    while(tmpV != NULL){ // 정점 하나 지나칠때마다 카운트
        cnt++;
        tmpV=tmpV->nextV;
    }
    return cnt;
}
int num_of_edge(G* g){
    V* tmpV = g->headV;
    int allE = 0;

    while(tmpV != NULL){
        allE += degree_of_vertex(tmpV);
        tmpV = tmpV->nextV;
    }
    return allE/2;
}
void rename_vertex(V* v,element data){
    v->_data = data;
}
int path_exist(V* startV,V* endV){
    if(startV==endV) return 1;
    if(startV->visited == 1) return 0;
    // 탐색 시작
    E* tmpE = startV ->headE;
    startV->visited =1 ;
    while(tmpE != NULL){
        if (path_exist(tmpE->curV,endV) ==1) return 1;
        tmpE= tmpE->nextE;
    }
    return 0;
}
void clear(G* g){
    V* tmpV1 = g->headV;
    V* tmpV2 ;
    while(tmpV1 != NULL){
        tmpV2 = tmpV1;
        tmpV1 = tmpV1 ->nextV;
        delete_vertex(g,tmpV2);
    }
}
int maxdegreeofG(G* g){// 창작 기능 1 그래프의 최대 차수 구하기
    V* tmpV = g->headV;

    int maxcnt =0;
    int tmpcnt ;

    while ( tmpV != NULL){
        tmpcnt=degree_of_vertex(tmpV);
        if(tmpcnt >= maxcnt) maxcnt = tmpcnt;
        tmpV = tmpV->nextV;
    }

    return maxcnt;
}
int mindegreeofG(G* g){ // 창작 기능 2 그래프의 최소 차수 구하기
    V* tmpV = g->headV;
    int mincnt;
    int tmpcnt;

    mincnt = degree_of_vertex(g->headV);

    while ( tmpV != NULL){
        tmpcnt=degree_of_vertex(tmpV);
        if(tmpcnt <= mincnt) mincnt = tmpcnt;
        tmpV = tmpV->nextV;
    }
    return mincnt;
}
int minTomax(G* g){// 창작 기능 3 그래프의 최대 차수와 최소 차수의 차이값 구하기
    return maxdegreeofG(g) - mindegreeofG(g);
}