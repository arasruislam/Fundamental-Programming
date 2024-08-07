from django.shortcuts import render
from .forms import contactForm, StudentData


# Create your views here.
def home(request):
    return render(request, "./first_app/home.html")


def about(request):
    if request.method == "POST":
        name = request.POST.get("username")
        email = request.POST.get("email")
        select = request.POST.get("select")
        return render(
            request,
            "./first_app/about.html",
            {"username": name, "email": email, "select": select},
        )
    else:
        return render(request, "./first_app/about.html")


def submit_form(request):
    # print(request.POST)
    # if request.method == "POST":
    #     name = request.POST.get("username")
    #     email = request.POST.get("email")
    #     return render(
    #         request, "./first_app/form.html", {"username": name, "email": email}
    #     )
    # else:
    return render(request, "./first_app/form.html")


def djangoForm(request):
    if request.method == "POST":
        Form = contactForm(request.POST, request.FILES)
        if Form.is_valid():
            # file = Form.cleaned_data["file"]
            # with open("./first_app/upload/" + file.name, "wb+") as destination:
            #     for chunk in file.chunks():
            #         destination.write(chunk)

            print(Form.cleaned_data)
            # return render(request, "./first_app/django_form.html", {"form": Form})
    else:
        Form = contactForm()
    return render(request, "./first_app/django_form.html", {"form": Form})


def StudentForm(request):
    if request.method == "POST":
        form = StudentData(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = StudentData()
    return render(request, "./first_app/django_form.html", {"form": form})
