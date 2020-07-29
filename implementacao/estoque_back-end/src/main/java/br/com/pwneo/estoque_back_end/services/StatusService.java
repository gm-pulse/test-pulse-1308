package br.com.pwneo.estoque_back_end.services;

import br.com.pwneo.estoque_back_end.models.Status;
import br.com.pwneo.estoque_back_end.repositories.StatusRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class StatusService {

    @Autowired
    private StatusRepository repository;

    public List<Status> findAll() {
        return this.repository.findAll();
    }

    public Status findById(Long id) {
        return this.repository.findById(id).get();
    }
}
