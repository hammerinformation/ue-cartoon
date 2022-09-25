

#include "WomanAnimInstance.h"

void UWomanAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	if (TryGetPawnOwner()) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();



	}
}