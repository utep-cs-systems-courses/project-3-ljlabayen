	.arch msp430g2553

	.p2align 1,0
JT:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global state_advance
state_advance:
	cmp #5, &switch_state_changed	; compare switch to 5
	jhs default
	mov &switch_state_changed, r12
	add r12, r12 		; make space
	mov JT(r12), r0 	; put r12 into counter
case1:
	call #randomSong
	call #redLights
	jmp end
case2:
	add #1, redrawScreen
	call #triangleShow
	call #sharkSong
	call #dimBlink
	jmp end
case3:
	call #errorSong
	call #redLights
	call #errorSong
	jmp end
case4:
	call #spongebobSong
	call #redLights
	jmp end
default:
	jmp end
end:
	ret
