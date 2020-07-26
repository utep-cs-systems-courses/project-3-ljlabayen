	.arch msp430g2553

	.p2align 1,0
	.data
state:	.byte 0

	.text
curr:
	.word note0
	.word note1
	.word note2
	.word note3
	
	.global randomBuzz
randomBuzz:

	mov #2, r12
	cmp.b &state, r12 	; compare if state is less than 2
	jl default		; 2 - state < 0

	mov.b &state, r12	; read current state
	add r12, r12		; r12 = 2*state
	mov curr(r12), r0	; jmp curr[state]

	
note0:	mov #2500, r12		; use 2500 to set perioid for buzzer
	call #buzzer_set_period
	mov.b #1, &state	; next state
	jmp end

note1:	mov #4000, r12
	call #buzzer_set_period
	mov.b #2, &state
	jmp end

note2:	mov #5000, r12
	call #buzzer_set_period
	mov.b #3, &state
	jmp end
	
note3:	mov #0, r12
	call #buzzer_set_period
	mov.b #4, &state
	jmp end

default:mov #0, r12
	call #buzzer_set_period

end:
	ret
