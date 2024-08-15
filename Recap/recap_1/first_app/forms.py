from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm


class RegistrationForm(UserCreationForm):
    class Meta:
        model = User
        # fields = "__all__"
        fields = ["username", "first_name", "last_name", "email"]
