## [C++ OpenCV]
### 1. 엠보싱 필터 효과 

입력영상에서 픽셀 값 변화가 적은 평탄한 영역은 회색으로 설정하고 객체의 경계 부분은 좀 더 밝거나 어둡게 설정

```c++
float mask[] = { 
    -1, -1 ,0
    ,-1, 0, 1,
     0, 1, 1 
    };
Mat emboss(3, 3, CV_32FC1, mask); 

// filter2D() 함수 이용하여 엠보싱 필터링 적용 
filter2D(image, result, -1, emboss, Point(-1, -1), 128);

```

![엠보싱](https://user-images.githubusercontent.com/81904943/140019899-127c9713-6448-44fa-adee-88ddc288823b.PNG)

-----

### 2. 블러링 필터 효과

입력 영상을 초점이 맞지 않듯이 영상을 흐릿하고 부드럽게 만드는 필터링 기법

```c++
blur(image, result, Size(5, 5)); 
```

![#2번](https://user-images.githubusercontent.com/81904943/140021155-a1416eac-865e-4ef2-b2d9-41913e700730.PNG)

----

### 3. 가우시안 스무딩 필터링 효과

입력 영상을 흐리게 하거나 노이즈를 줄 때 사용하는 필터링 기법

```c++
GaussianBlur(image, result, Size(), 3); 
```

![가우시안](https://user-images.githubusercontent.com/81904943/140021279-b996e681-94cd-439c-8713-48682f252566.PNG)

----

### 4. 샤프닝 필터링 효과

입력 영상의 윤곽을 좀 더 뚜렷하게 보이도록 처리하는 필터링 기법 

```c++
float data[] = {      
		-1, -1, -1,
		-1, 9, -1,
		-1, -1, -1
	};

	Mat sharp(3, 3, CV_32FC1, data);
	// CV_32FC 영상의 깊이 

	filter2D(image, result, -1, sharp, Point(-1, -1), 4);
```

![샤프닝](https://user-images.githubusercontent.com/81904943/140021503-79fc41fd-0b4e-4972-9b17-a68c129a8f78.PNG)

