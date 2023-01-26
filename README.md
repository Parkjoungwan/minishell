# 서브젝트 요약

---

### 나만의 쉘 구현하기

미니 쉘은 우리가 지금까지 사용하던 쉘의 요소들을 뜯어봅니다.

명령어 입력, 기본 내장함수 몇가지, 그리고 명령어를 어떻게 쉘이 파싱하고 인식하는지, 작업 히스토리는 어떻게 저장되고 있는지.

물론, 우리가 만들건 쉘의 모든건 아니고 아마 쉘이 만들어진 원리와 코드가 일치하지도 않겠지만 대략적인 작동 원리는 이번 서브젝트를 통해서 이해할 수 있습니다.

# 실행방법

makefile을 사용해 빌드해주세요.

```jsx
make all
```

만약 “readline/readline.h”이 존재하지 않는다고하면 라이브러리를 설치해주세요.

```jsx
sudo apt-get install libreadline-dev
```

빌드가 성공했다면, minishell 파일을 실행시켜주시고, 평소 shell을 사용하듯 사용하시면 됩니다.

```jsx
./minishell
```

# 실행예시
![image](https://user-images.githubusercontent.com/48785968/214744135-8eecf7f6-cfb8-469c-9dd6-d7eb7cb35dbc.png)
