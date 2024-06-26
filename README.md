# Algorithm
2022년 2월 SW개발병 입대 이후 알고리즘 공부 기록용 레포지토리입니다.

 - https://programmers.co.kr/
     * [프로그래머스 커리어](https://career.programmers.co.kr/)에 실전 모의고사 같은 것들이 자주 올라온다. 간간히 찾아가서 풀어 볼 것
  - https://leetcode.com/
     * daily challenge를 꾸준하게 풀어보자
- https://www.acmicpc.net/
     * **실/골 랜덤 디펜스**로 실전 감각을 길러 보자
     * solved.ac에 class별 문제가 있던데, 그것도 풀어 볼 것
 - https://codeforces.com/
     * 심심할 때 virtual로 풀어보기
     * 코포는 코테나 면접준비용으로는 뭔가 맞지 않는 느낌? 물론 하면 좋겠지만 선택과 집중을 하자

## 목표 및 우선순위
`기업 코딩테스트를 100%로 통과할 수 있을 만한 실력`을 갖추기 위해 다음 목표들을 설정했습니다.
1. ~~programmers lv2, lv3 올솔~~ - 완료
    - 문제가 추가되면 찾아가서 풀어보기
2. leetcode daily challenge, contest, featured 풀기
3. 백준 실/골 랜덤디펜스 
    - `*s..g !@$me` 명령어로 내가 풀지 않은 실버~골드 문제를 풀 수 있다.
    - 문제 티어, 태그, 푼 사람 등 최대한 숨기고, 코테와 유사하게 30분에 풀 수 있도록 타이머를 사용할 것.
    - 시간은 2시간~3시간 정도가 적당한 것 같다. (2시간은 풀이, 1시간은 푼 문제 복기 및 정리)
4. 코테 시즌이 가까워지면 programmers 기출 다시 풀어보기 (특히 구현 문제들)

## 정보 블로그들
 - https://subinium.github.io/PS-Study-Types-and-Complements/?msclkid=d60b6cd9a9be11ecb723c667121b88da
 - https://blog.naver.com/kks227
 - https://firesoil-it.tistory.com/26?category=983388

## 개발환경
GCP의 VM에 Code Server를 올리고, C++ 개발환경 세팅 후 개인 도메인과 연결해서 사용했습니다. [환경 구성 방법](https://hyelie.tistory.com/entry/GCP-VS-Code-Server?category=947331)


## Commit 메시지 양식

### Commit Template
다음 명령어를 사용해 commit template을 사용할 수 있습니다.
```
# commit template 등록
git config --local commit.template .gitmessage

# commit template를 사용해 commit 작성
git commit
```

### 문제를 푼 경우
`solve: [문제 출처] [문제이름]`으로 통일합니다.

description에는 난이도, 걸린 시간 및 메모하고 싶은 내용을 작성합니다.

#### 예시
```
solve: BOJ 14906. 스러피
Gold 4, 50분

solve: Leetcode 59. Spiral Matrix II
Medium, 40분
```


### 이외의 경우
문제를 푸는 경우를 제외하고는 README 수정, 폴더 정리 등 간단한 작업만 수행할 것으로 예상됩니다.

이 경우 `docs`, `cleanup` 등의 상황에 맞는 헤더를 사용합니다.

#### 예시
```
# readme 수정 시
docs: Edit README.md

# 폴더 정리 시
cleanup: Remove unused files
```

## 알고리즘 정리 및 기록
[블로그](https://hyelie.tistory.com)
의 PS-Log 탭, Algorithm 탭에 각각 정리했습니다.
 - PS-Log 탭에는 풀었던 문제들의 접근 과정, 복기 내용을 작성
 - Algorithm 탭에는 알고리즘의 증명, 시간복잡도, 코드 등을 작성