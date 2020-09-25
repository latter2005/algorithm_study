#define left(x) (x+1)&3 
#define right(x) (x-1)&3

int dx[] = { 1, 0, -1, 0 },
    dy[] = { 0, 1, 0, -1 }; // 하 오 상 왼

unsigned int cur_d;

// unsigned 일 때 mod연산을 사용하지 않고 AND 연산을 통해 다음 방향으로 변환 