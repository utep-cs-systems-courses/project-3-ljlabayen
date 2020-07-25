	.arch msp430g2553

	.p2align 1,0
	.data
state:	.byte 0

	.text
curr:
	.word note1
	.word note2
	.word note3

	.global randomBuzz
randomBuzz:

	mov #2, r12
	cmp.b &state, r12
	jl default

	mov.b &state, r12
	add r12, r12
	mov curr(r12), r0

	
note1:	mov #2500, r12
	call #buzzer_set_period
	mov.b #2, &state
	jmp end

note2:	mov #5000, r12
	call #buzzer_set_period
	mov.b #3, &state
	jmp end

note3:	mov #3300, r12
	call #buzzer_set_period
	mov.b #1, &state
	jmp end


default:mov #0, r12
	call #buzzer_set_period

end:
	ret
