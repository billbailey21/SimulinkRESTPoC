from django.db import models

# Create your models here.


class TodoItem(models.Model):
    todo_name = models.CharField("Task", max_length=500)
    todo_description = models.TextField("Description", blank=True, null=True)
    date_created = models.DateTimeField("Date Created", auto_now_add=True)
    is_completed = models.BooleanField("Completed", default=False)
