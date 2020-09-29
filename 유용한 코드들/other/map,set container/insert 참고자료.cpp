insert 사용법 참고
insert결과	첫번째(iterator)			두번째(bool)	언제 발생
성공		insert되어진 element의 iterator	true		중복된 Key가 존재 하지 않을때
실패		중복된 Key의 element의 iterator	false		중복된 Key가 존재 할때

operator[]의 경우 insert한 결과의 iterator->second를 돌려준다(second의 성공, 실패 여부와 관계없이)는 사실을 알고 있다면,
operator[]를 호출하는 순간 insert가 발생한 다는 것을 알고 있어야 한다.

-> insert를 성공 or 실패에 대하여 알 수 없을 때 다음 코드를 사용하여 메모리 할당의 부담을 줄일 수 있음
auto itr = temp.lower_bound(1);
if ((itr == temp.end()) || std::less<int>()(1, itr->first)){ //greater<int>
    temp.insert(itr, { 1, new Foo });
}