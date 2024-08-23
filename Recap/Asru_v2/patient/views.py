from .serializers import PatientSerializer, RegistrationSerializer
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework import viewsets
from .models import Patient


# Create your views here.
class PatientUsViewSet(viewsets.ModelViewSet):
    queryset = Patient.objects.all()
    serializer_class = PatientSerializer


class UserRegistrationApiView(APIView):
    serializer_class = RegistrationSerializer

    def post(self, request):
        serializer = self.serializer_class(data=request.data)
        if serializer.is_valid():
            user = serializer.save()
            print(user)
            return Response("Done...")
        
        return Response(serializer.errors)
