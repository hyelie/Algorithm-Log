# Daily Algorithm Study
## 참여 방법
1. 사용자 이름으로 폴더를 만듭니다.
2. 각자 풀고 싶은 문제를 풀고, 해당 폴더 안에 답안을 업로드합니다. BOJ, Leetcode, Programmers, Codeforce 등 원하는 문제를 풉니다.


<br>

## Branch 생성 규칙
혹시 모를 충돌을 피하기 위해 branch를 사용하며, 이름은 `hyelie`, `cgg7777`와 같은 사용자 이름을 권장합니다.

Pull Request는 자유롭게 사용합니다.

#### 예시)
```
git checkout -b hyelie
```

<br>

## Commit 메시지 양식
### 문제를 푼 경우
`solve: [문제 출처] [문제이름]`으로 통일합니다.

description에는 난이도, 걸린 시간 및 메모하고 싶은 내용을 작성합니다.

#### 예시)
```
solve: BOJ 14906. 스러피
Gold 4, 50분

solve: Leetcode 59. Spiral Matrix II
Medium, 40분
```

<br>

### 이외의 경우
문제를 푸는 경우를 제외하고는 README 수정, 폴더 정리 등 간단한 작업만 수행할 것으로 예상됩니다.

이 경우 `docs`, `cleanup` 등의 상황에 맞는 헤더를 사용합니다.

#### 예시)
```
# readme 수정 시
docs: Edit README.md

# 폴더 정리 시
cleanup: Remove unused files
```
<br>

### Commit Template
다음 명령어를 사용해 commit template을 사용할 수 있습니다.
```
# commit template 등록
git config --local commit.template .gitmessage

# commit template를 사용해 commit 작성
git commit
```



## 참여자
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/hyelie">
        <img src="https://avatars.githubusercontent.com/hyelie" width="100px;" alt=""/><br/>
        <sub><b>hyelie</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/cgg7777">
        <img src="https://avatars.githubusercontent.com/cgg7777" width="100px;" alt=""/><br/>
        <sub><b>cgg7777</b></sub>
      </a>
    </td>
  </tr>
</table>

>스터디를 같이 하고 싶은 분들은 참여자 중 한 명에게 연락 부탁드립니다.